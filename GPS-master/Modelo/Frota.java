package GPS.Modelo;

import GPS.gpsproject.Notifica;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TextField;

import java.io.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Frota implements Constantes, Serializable {

    private List<Veiculo> veiculos = new ArrayList<>();
    private Notifica notifica;

    public Frota() {
        try {
            this.veiculos = getFrotaBD();
        } catch (ClassNotFoundException ex) {
            System.exit(4);
        } catch (IOException ex) {
            criaBD();
        }
    }

    private void criaBD() {
        File bd = new File(BD_FROTA_BIN);

        bd.getParentFile().mkdirs();
        try {
            bd.createNewFile();
        } catch (IOException e) {
            System.exit(10);
        }
    }

    public static void preencheDados(String matricula, TextField modelo, TextField tipo, DatePicker registo) {
        try (BufferedReader br = new BufferedReader(new FileReader(BD_MATRICULAS_TXT))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                Scanner sc = new Scanner(linha);
                String matriculaLida = sc.next();
                if (matriculaLida.equals(matricula)) {
                    registo.setValue(LocalDate.of(sc.nextInt(), sc.nextInt(), sc.nextInt()));
                    modelo.setText(sc.next() + " " + sc.next());
                    tipo.setText(sc.next());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static boolean getExists(String matricula) {
        try (BufferedReader br = new BufferedReader(new FileReader(BD_MATRICULAS_TXT))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                Scanner sc = new Scanner(linha);
                String matriculaLida = sc.next();
                if (matriculaLida.equals(matricula)) {
                    return true;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

    /////////////////////////////////////////////////REGISTAR VEICULO
    public void RegistaVeiculo(Veiculo veiculo) {
        veiculos.add(veiculo);
        try {
            guardarFrotaBD();
        } catch (IOException ignore) {
        }
    }

    /////////////////////////////////////////////////ENIMINAR VEICULO
    public void eliminaVeiculo(String matricula) {
        Veiculo veiculo = pesquisaVeiculo(matricula);

        if (veiculo != null) {
            veiculos.remove(veiculo);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCOES AUXILIARES
    public Veiculo pesquisaVeiculo(String valor) {
        for (Veiculo v : veiculos) {
            if (v.matricula.equals(valor) || v.nome.equals(valor)) {
                return v;
            }
        }
        return null;
    }

    public List<String> getNomesVeiculos() {
        List<String> lista = new ArrayList<>();

        for (Veiculo veiculo : veiculos) {
            lista.add(veiculo.nome);
        }

        return lista;
    }

    public List<Evento> getEventosTotal() {
        List<Evento> allEventos = new ArrayList<>();

        for (Veiculo veiculo : veiculos) {
            allEventos.addAll(veiculo.eventos);
        }
        return allEventos;
    }

    public void guardarFrotaBD() throws IOException {

        try (ObjectOutputStream oout = new ObjectOutputStream(new FileOutputStream(BD_FROTA_BIN))) {
            oout.writeObject(this);
        }
    }

    private List<Veiculo> getFrotaBD() throws ClassNotFoundException, IOException {
        try (ObjectInputStream oin = new ObjectInputStream(new FileInputStream(BD_FROTA_BIN))) {
            Frota frota = (Frota) oin.readObject();
            return frota.veiculos;
        }
    }

    public List<Veiculo> getVeiculos() {
        return veiculos;
    }
}




