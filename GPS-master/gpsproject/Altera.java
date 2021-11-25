package GPS.gpsproject;

import GPS.Modelo.Frota;
import GPS.Modelo.Veiculo;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

public class Altera {
    public static void display(Frota frota) {
        List<Veiculo> lista = frota.getVeiculos();
        AtomicInteger atual = new AtomicInteger();

        Stage window = new Stage();
        Parent root;
        try {
            root = FXMLLoader.load(Altera.class.getResource("FXML/Altera.fxml"));
        } catch (IOException e) {
            return;
        }
        root.setStyle("-fx-effect: innershadow(gaussian, #039ed3, 2, 1.0, 0, 0);");
        Scene scene = new Scene(root);

        Label nome = (Label) scene.lookup("#nome");
        TextField kms = (TextField) scene.lookup("#kms");
        Button proximo = (Button) scene.lookup("#proximo");

        nome.setText(lista.get(atual.get()).getNome());
        kms.setText(String.valueOf(lista.get(atual.get()).getKmReais()));

        proximo.setOnAction(event -> {
            int valor = Integer.parseInt(kms.getText());

            if (valor <= 0 || valor > 1000000) {
                Alert.display("Alerta", "Verifique se os campos possuem dados válidos!\n\n" +
                        "- Kilómetros reais entre 1 e 1,000,000\n" +
                        "- Kilómetros mensais entre 1 e 10,000");
            } else {
                lista.get(atual.get()).setKmReais(valor);

                atual.getAndIncrement();

                if (atual.get() == lista.size()) {
                    window.close();
                } else {
                    nome.setText(lista.get(atual.get()).getNome());
                    kms.setText(String.valueOf(lista.get(atual.get()).getKmReais()));
                }

            }
        });

        window.initModality(Modality.APPLICATION_MODAL);
        window.initStyle(StageStyle.UNDECORATED);
        window.setScene(scene);
        window.showAndWait();
    }
}
