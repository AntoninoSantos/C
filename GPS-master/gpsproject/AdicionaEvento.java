package GPS.gpsproject;

import GPS.Modelo.Constantes;
import GPS.Modelo.Evento;
import GPS.Modelo.Veiculo;
import GPS.gpsproject.images.BibliotecaImagens;
import javafx.collections.FXCollections;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;

import static GPS.gpsproject.calendar.DateUtils.noPastDates;

public class AdicionaEvento implements BibliotecaImagens, Constantes {
    private static boolean choice;

    public static boolean display(Veiculo veiculo) {
        Stage window = new Stage();
        Parent root;
        try {
            root = FXMLLoader.load(AdicionaEvento.class.getResource("FXML/AdicionaEvento.fxml"));
        } catch (IOException e) {
            return false;
        }
        root.setStyle("-fx-effect: innershadow(gaussian, #039ed3, 2, 1.0, 0, 0);");
        Scene scene = new Scene(root);

        TextField nome = (TextField) scene.lookup("#nome");
        DatePicker data = (DatePicker) scene.lookup("#data");
        ChoiceBox tipo = (ChoiceBox) scene.lookup("#tipo");
        CheckBox notificar = (CheckBox) scene.lookup("#notificar");
        ChoiceBox tempo = (ChoiceBox) scene.lookup("#tempo");

        Button cancelar = (Button) scene.lookup("#cancelar");
        Button confirmar = (Button) scene.lookup("#confirmar");

        tempo.setItems(FXCollections.observableArrayList(tempos));
        tempo.setDisable(true);

        tipo.setItems(FXCollections.observableArrayList(TipoEvento.values()));

        notificar.setOnAction(event -> {
            tempo.setDisable(!notificar.isSelected());
        });

        data.setDayCellFactory(noPastDates);

        confirmar.setGraphic(new ImageView(check));
        cancelar.setGraphic(new ImageView(cross));

        confirmar.setOnAction(event -> {
            if(!nome.getText().trim().equals("") && data.getValue() != null && tipo.getValue() != null) {
                if(notificar.isSelected()) {
                    if (tempo.getValue() != null) {
                        veiculo.criaEvento(new Evento(data.getValue(), nome.getText(), (TipoEvento) tipo.getValue(), (String) tempo.getValue()));
                        window.close();
                    } else {
                        Alert.display("Erro", "Tem que especificar o tempo da notificação");
                    }
                } else {
                    veiculo.criaEvento(new Evento(data.getValue(), nome.getText(), (TipoEvento) tipo.getValue()));
                    window.close();
                }
            } else {
                Alert.display("Alerta", "Não pode registar campos em branco");
            }
        });

        cancelar.setOnAction(event -> window.close());

        window.initModality(Modality.APPLICATION_MODAL);
        window.initStyle(StageStyle.UNDECORATED);
        window.setScene(scene);
        window.showAndWait();

        return choice;
    }
}

