package GPS.Modelo;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

abstract public class Veiculo implements Constantes, Serializable {

    //Dados introduzidos
    protected String nome;
    protected String matricula;
    private int kmReais;
    private int kmMensais;
    private Seguro seguro;

    //Dados vindos da BD
    protected LocalDate dataRegistoMatricula;
    protected String modelo;
    protected int intervaloKmsOleo;
    protected int kmsMudancaCorreia;

    //Lista de eventos que vão ser criados
    protected List<Evento> eventos;

    public Veiculo(String nome, String matricula, int KmReais, int KmMensais, String seguradora, LocalDate dataRegistoSeguro, String tipoSeguro) {
        this.nome = nome;
        this.matricula = matricula;
        this.kmReais = KmReais;
        this.kmMensais = KmMensais;
        this.seguro = new Seguro(seguradora, tipoSeguro, dataRegistoSeguro);
        this.eventos = new ArrayList<>();
        kmsMudancaCorreia = KMS_NECESSARIOS_MUDANCA_CORREIA;

        getDados();

        //criar eventos
        calcularProximaDataPagamentoImpostoCirculacao(LocalDate.now());
        calcularProximaDataDePagamentoSeguro(LocalDate.of(LocalDate.now().getYear(), dataRegistoSeguro.getMonthValue(),
                dataRegistoSeguro.getDayOfMonth()));
        calcularProximaDataInspecao(LocalDate.now());
        calcularProximaDataMudancaOleo(LocalDate.now());
        calcularProximaDataMudancaDeCorreia(LocalDate.now());
    }

    private void getDados() {
        try (BufferedReader br = new BufferedReader(new FileReader(BD_MATRICULAS_TXT))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                Scanner sc = new Scanner(linha);
                String matriculaLida = sc.next();
                if (matriculaLida.equals(matricula)) {
                    dataRegistoMatricula = LocalDate.of(sc.nextInt(), sc.nextInt(), sc.nextInt());
                    modelo = sc.next() + " " + sc.next();

                    sc.next();

                    intervaloKmsOleo = sc.nextInt();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////GETS E SETS
    public int getKmReais() {
        return kmReais;
    }

    public int getKmMensais() {
        return kmMensais;
    }

    public String getMatricula() {
        return matricula;
    }

    public Seguro getSeguro() {
        return seguro;
    }

    public void setKmReais(int KmReais) {
        this.kmReais = KmReais;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CALCULAR
    private void calcularProximaDataPagamentoImpostoCirculacao(LocalDate data) {
        eventos.add(new Evento(getDataComMaisUmAno(data), PAGAMENTO_IMPOSTO, TipoEvento.OBRIGACOES));
    }

    private void calcularProximaDataDePagamentoSeguro(LocalDate data) {
        eventos.add(new Evento(getDataComMaisUmAno(data), PAGAMENTO_SEGURO, TipoEvento.OBRIGACOES));
    }

    private void calcularProximaDataInspecao(LocalDate data) {
        LocalDate proxData = getDataProximaInspecao(data);
        //Aqui é necessário verificar se a data da proxima ispeção vem a null. Uma vez que se o veiculo for uma moto com menos de 250cc não é necessário criar um evento.
        if (proxData != null) {
            eventos.add(new Evento(proxData, INSPECAO, TipoEvento.OBRIGACOES));
        }
    }

    private void calcularProximaDataMudancaOleo(LocalDate data) {
        int kmsNecessarios = kmReais + intervaloKmsOleo, nMeses = 0, aux = kmReais;
        while (aux <= kmsNecessarios) {
            aux += (nMeses++) * kmMensais;
        }
        eventos.add(new Evento(data.plusMonths(nMeses), MUDANCA_OLEO, TipoEvento.MANUTENCOES));
    }

    private void calcularProximaDataMudancaDeCorreia(LocalDate data) {
        int nMeses = 0, aux = kmReais;

        for (int i = 1; i <= 10; i++) {
            if (kmReais < KMS_NECESSARIOS_MUDANCA_CORREIA * i) {
                kmsMudancaCorreia = KMS_NECESSARIOS_MUDANCA_CORREIA * i;
                break;
            }
        }
        if ((kmReais + kmMensais > kmsMudancaCorreia)) {
            kmsMudancaCorreia += KMS_NECESSARIOS_MUDANCA_CORREIA;
            eventos.add(new Evento(LocalDate.now(), MUDANCA_CORREIA, TipoEvento.MANUTENCOES));
            return;
        }

        while (aux < kmsMudancaCorreia && nMeses < 24) {
            aux += kmMensais;
            nMeses++;
        }

        eventos.add(new Evento(data.plusMonths(nMeses), MUDANCA_CORREIA, TipoEvento.MANUTENCOES));
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCOES AUXILIARES
    protected LocalDate getDataComMaisUmAno(LocalDate data) {
        //O ano da data que entra vai ser alterado para o ano corrente + 1
        return LocalDate.of(data.getYear() + UM_ANO, data.getMonthValue(), data.getDayOfMonth());
    }

    abstract protected LocalDate getDataProximaInspecao(LocalDate data);

    public List<Evento> getEventos() {
        return eventos;
    }

    public String getNome() {
        return nome;
    }

    public LocalDate getDataRegistoMatricula() {
        return dataRegistoMatricula;
    }

    public String getModelo() {
        return modelo;
    }

    @Override
    public String toString() {
        String s = "";
        s += "Matricula: " + matricula + " " + dataRegistoMatricula + "\n";
        s += "Modelo: " + modelo + "\n";
        s += "KmReais: " + kmReais + "\n";
        s += "KmMensais: " + kmMensais + "\n";
        s += seguro.toString();

        return s;
    }

    public void altera(String nome, String seguradora, String tipoSeguro, LocalDate registoSeguro, int kmreais, int kmmensais) {
        this.nome = nome;
        this.seguro = new Seguro(seguradora, tipoSeguro, registoSeguro);
        this.kmReais = kmreais;
        this.kmMensais = kmmensais;
    }

    public void criaEvento(Evento evento) {
        eventos.add(evento);
    }

    public void realizaEvento(Evento evento, double custo) {
        evento.setCusto(custo);
        evento.setCheck(true);

        switch (evento.getDescricao()) {
            case INSPECAO:
                calcularProximaDataInspecao(evento.getData());
                break;
            case MUDANCA_CORREIA:
                calcularProximaDataMudancaDeCorreia(evento.getData());
                break;
            case MUDANCA_OLEO:
                calcularProximaDataMudancaOleo(evento.getData());
                break;
            case PAGAMENTO_IMPOSTO:
                calcularProximaDataPagamentoImpostoCirculacao(evento.getData());
                break;
            case PAGAMENTO_SEGURO:
                calcularProximaDataDePagamentoSeguro(evento.getData());
                break;
        }
    }
}
