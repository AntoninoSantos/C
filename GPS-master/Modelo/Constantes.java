package GPS.Modelo;

public interface Constantes {

    enum TipoEvento {
        REPARACAO, MECANICA, MANUTENCOES, OBRIGACOES
    }

    enum TipoVeiculo {
        MOTOCICLO, LIGEIRO, PESADO
    }
    
    
    String INSPECAO = "Inspeção";
    String MUDANCA_OLEO = "Mudança de óleo";
    String PAGAMENTO_SEGURO = "Pagamento de Seguro";
    String MUDANCA_CORREIA = "Mudança de correia";
    String PAGAMENTO_IMPOSTO = "Pagamento de imposto de circulação";

    int CC_NECESSARIOS_PARA_INSPECAO = 250;
    int KMS_NECESSARIOS_MUDANCA_CORREIA = 100000;

    String[] tempos = {"Uma semana antes", "2 dias antes", "1 dia antes", "No próprio dia"};
    int[] temposValores = {7, 2, 1, 0};

    String BD_MATRICULAS_TXT = "C:\\Users\\a21260315\\Desktop\\GPS_TP\\src\\GPS\\Modelo\\BDs\\BD.txt";
    String BD_FROTA_BIN = "C:\\tmp\\BD_Frota.dat";

//    File BD_MATRICULAS_TXT = new File("GPS/Modelo/BDs/BD.txt");
//    File BD_FROTA_BIN = new File("GPS/Modelo/BDs/BD_Frota.dat");

    int UM_ANO = 1;
    int DOIS_ANOS = 2;
    int QUATRO_ANOS = 4;
    int OITO_ANOS = 8;
}
