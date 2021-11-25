
package GPS.Modelo;

import java.time.LocalDate;

public class Pesado extends Veiculo {

    public Pesado(String nome, String matricula, int KmReais, int KmMensais, String seguradora, LocalDate dataRegistoSeguro, String tipoSeguro) {
        super(nome, matricula, KmReais, KmMensais, seguradora, dataRegistoSeguro, tipoSeguro);
    }



    @Override
    protected LocalDate getDataProximaInspecao(LocalDate data) {
       return getDataComMaisUmAno(data);
    }

}
