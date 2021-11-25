package GPS.gpsproject;

import GPS.Modelo.*;
import GPS.gpsproject.images.BibliotecaImagens;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TextField;
import javafx.scene.control.TitledPane;
import javafx.scene.image.ImageView;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;

import static GPS.gpsproject.calendar.DateUtils.noFutureDates;

public class Adicionar implements Constantes, BibliotecaImagens {
    private static Veiculo veiculo;

    public static Veiculo display() {
        Stage window = new Stage();
        Parent root;
        try {
            root = FXMLLoader.load(Adicionar.class.getResource("FXML/Adicionar.fxml"));
        } catch (IOException e) {
            return null;
        }
        root.setStyle("-fx-effect: innershadow(gaussian, #039ed3, 2, 1.0, 0, 0);");
        Scene scene = new Scene(root);

        TitledPane detalhes = (TitledPane) scene.lookup("#detalhes");
        TitledPane seguro = (TitledPane) scene.lookup("#seguro");
        TitledPane outros = (TitledPane) scene.lookup("#outros");

        detalhes.applyCss();
        detalhes.layout();

        seguro.applyCss();
        seguro.layout();

        outros.applyCss();
        outros.layout();

        TextField nome = (TextField) scene.lookup("#nome");
        TextField modelo = (TextField) scene.lookup("#modelo");
        TextField matricula = (TextField) scene.lookup("#matricula");
        TextField tipo = (TextField) scene.lookup("#tipo");
        TextField kmReais = (TextField) scene.lookup("#kmreais");
        TextField kmMensais = (TextField) scene.lookup("#kmmensais");
        TextField seguradora = (TextField) scene.lookup("#seguradora");
        TextField tipoSeguro = (TextField) scene.lookup("#tiposeguro");
        DatePicker registoMatricula = (DatePicker) scene.lookup("#registomatricula");
        DatePicker registoSeguro = (DatePicker) scene.lookup("#registoseguro");
        Button confirmar = (Button) scene.lookup("#adicionar");
        Button cancelar = (Button) scene.lookup("#cancelar");

        matricula.textProperty().addListener((observable, oldValue, newValue) -> {
            if (Frota.getExists(matricula.getText())) Frota.preencheDados(matricula.getText(), modelo, tipo, registoMatricula);
        });

        matricula.focusedProperty().addListener((observable, oldValue, newValue) -> {
            if (!Frota.getExists(matricula.getText()) && !matricula.isFocused()) Alert.display("Alerta", "A matrícula inerida não é válida!");
        });

        registoSeguro.setDayCellFactory(noFutureDates);

        confirmar.setGraphic(new ImageView(check));
        cancelar.setGraphic(new ImageView(cross));

        confirmar.setOnAction(event -> {
            if(!nome.getText().trim().equals("") &&
                    !modelo.getText().trim().equals("") &&
                    !tipo.getText().trim().equals("") &&
                    !kmMensais.getText().trim().equals("") &&
                    !kmReais.getText().trim().equals("") &&
                    !seguradora.getText().trim().equals("") &&
                    !tipoSeguro.getText().trim().equals("") &&
                    registoMatricula.getValue() != null &&
                    registoSeguro.getValue() != null) {
                try {
                    int kms = Integer.parseInt(kmMensais.getText());
                    int kmsr = Integer.parseInt(kmReais.getText());

                    if(kms <= 0 || kmsr <= 0 || kms > 10000 || kmsr > 1000000) {
                        Alert.display("Alerta", "Verifique se os campos possuem dados válidos!\n" +
                                "- Kilómetros reais entre 1 e 1,000,000\n" +
                                "- Kilómetros mensais entre 1 e 10,000");
                    } else {
                        switch (tipo.getText()) {
                            case "LIGEIRO":
                                veiculo = new Ligeiro(nome.getText(), matricula.getText(), kmsr, kms, seguradora.getText(), registoSeguro.getValue(), tipoSeguro.getText());
                                break;
                            case "PESADO":
                                veiculo = new Pesado(nome.getText(), matricula.getText(), kmsr, kms, seguradora.getText(), registoSeguro.getValue(), tipoSeguro.getText());
                                break;
                            case "MOTOCICLO":
                                veiculo = new Motociclo(nome.getText(), matricula.getText(), kmsr, kms, seguradora.getText(), registoSeguro.getValue(), tipoSeguro.getText(), 0);
                                break;
                        }

                        window.close();
                    }
                } catch(NumberFormatException | NullPointerException e) {
                    Alert.display("Alerta", "Verifique se os campos possuem dados válidos!\n\n" +
                            "- Kilómetros reais entre 1 e 1,000,000\n" +
                            "- Kilómetros mensais entre 1 e 10,000");
                }
            } else {
                Alert.display("Alerta", "Não é possível guardar campos em branco");
            }
        });

        cancelar.setOnAction(event -> {
            veiculo = null;
            window.close();
        });

        window.initModality(Modality.APPLICATION_MODAL);
        window.initStyle(StageStyle.UNDECORATED);
        window.setScene(scene);
        Alert.display("Atenção", "Ao preencher a matrícula os campos inativos\nserão preenchidos automaticamente");
        window.showAndWait();

        return veiculo;
    }
}
