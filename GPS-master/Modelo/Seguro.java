package GPS.Modelo;

import java.io.Serializable;
import java.time.LocalDate;

public class Seguro implements Constantes, Serializable{

    String seguradora;
    String tipo;
    LocalDate dataRegisto;

    public Seguro(String Seguradora, String tipo, LocalDate dataRegito) {
        this.seguradora = Seguradora;
        this.tipo = tipo;
        this.dataRegisto = dataRegito;
    }

    public LocalDate getDataRegisto() {
        return dataRegisto;
    }

    public String getSeguradora() {
        return seguradora;
    }

    @Override
    public String toString() {
        String s = "Seguradora: " + seguradora + "\nData: "+ dataRegisto+ " " + "\nTipo: " + tipo;
        return s;
    }

    public String getTipo() {
        return tipo;
    }
}
