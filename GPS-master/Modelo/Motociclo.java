package GPS.Modelo;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.util.Scanner;

public class Motociclo extends Veiculo {
    private int cilindrada;
    public Motociclo(String nome, String matricula, int KmReais, int KmMensais, String seguradora, LocalDate dataRegistoSeguro, String tipoSeguro, int cilindrada) {
        super(nome, matricula, KmReais, KmMensais, seguradora, dataRegistoSeguro, tipoSeguro);

        getDados();
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
                    cilindrada = sc.nextInt();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    protected LocalDate getDataProximaInspecao(LocalDate data) {
       return cilindrada >= CC_NECESSARIOS_PARA_INSPECAO ? getDataComMaisUmAno(data) : null;
    }
    
    @Override
    public String toString() {  //falta a cilindrada
        String s = super.toString() + "\nCilindrada: " + cilindrada;
        return s;
    }
}
