package GPS.gpsproject;

import GPS.gpsproject.Sounds.BibliotecaSons;
import GPS.gpsproject.images.BibliotecaImagens;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;

public class Alert implements BibliotecaSons, BibliotecaImagens {
    public static void display(String title, String message) {
        Stage window = new Stage();
        Parent root;
        try {
            root = FXMLLoader.load(Alert.class.getResource("FXML/Warning.fxml"));
        } catch (IOException e) {
            return;
        }
        root.setStyle("-fx-effect: innershadow(gaussian, #039ed3, 2, 1.0, 0, 0);");
        Scene scene = new Scene(root);
        MediaPlayer mediaPlayer = new MediaPlayer(errorSound);

        ImageView imageView = (ImageView) scene.lookup("#imageView");
        Label warningTitle = (Label) scene.lookup("#messageLabel");
        Label warningMessage = (Label) scene.lookup("#detailsLabel");
        Button okButton = (Button) scene.lookup("#okButton");

        imageView.setImage(warning);
        warningTitle.setText(title);
        warningMessage.setText(message);

        okButton.setOnAction(e -> window.close());


        window.initModality(Modality.APPLICATION_MODAL);
        window.initStyle(StageStyle.UNDECORATED);
        window.setTitle("Alerta");
        window.setScene(scene);
        mediaPlayer.play();
        window.showAndWait();
    }
}
