package GPS.Modelo;

import java.time.LocalDate;

public class Ligeiro extends Veiculo {

    public Ligeiro(String nome, String matricula, int KmReais, int KmMensais, String seguradora, LocalDate dataRegistoSeguro, String tipoSeguro) {
        super(nome, matricula, KmReais, KmMensais, seguradora, dataRegistoSeguro, tipoSeguro);
    }

  
    @Override
    protected LocalDate getDataProximaInspecao(LocalDate dataCorrente) {
       if (dataCorrente.getYear() - dataRegistoMatricula.getYear() <= QUATRO_ANOS) {
            return LocalDate.of(dataCorrente.getYear() + QUATRO_ANOS, 
                    dataRegistoMatricula.getMonthValue(), dataRegistoMatricula.getDayOfMonth());
            
        } else if (dataCorrente.getYear() - dataRegistoMatricula.getYear() > QUATRO_ANOS && dataCorrente.getYear() - dataRegistoMatricula.getYear() <= OITO_ANOS) {
           return LocalDate.of(dataCorrente.getYear() + DOIS_ANOS, 
                    dataRegistoMatricula.getMonthValue(), dataRegistoMatricula.getDayOfMonth());
        } else {
            return LocalDate.of(dataCorrente.getYear() + UM_ANO,
                    dataRegistoMatricula.getMonthValue(), dataRegistoMatricula.getDayOfMonth());
        }
    }
}
