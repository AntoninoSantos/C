package GPS.gpsproject;

import GPS.gpsproject.Sounds.BibliotecaSons;
import GPS.gpsproject.images.BibliotecaImagens;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;

public class Confirm implements BibliotecaImagens, BibliotecaSons {
    private static boolean choice;

    public static boolean display() {
        Stage window = new Stage();
        Parent root;
        try {
            root = FXMLLoader.load(Confirm.class.getResource("FXML/Confirm.fxml"));
        } catch (IOException e) {
            return false;
        }
        root.setStyle("-fx-effect: innershadow(gaussian, #039ed3, 2, 1.0, 0, 0);");
        Scene scene = new Scene(root);
        MediaPlayer mediaPlayer = new MediaPlayer(errorSound);

        ImageView imageView = (ImageView) scene.lookup("#imageView");
        Button cancelButton = (Button) scene.lookup("#cancelButton");
        Button okButton = (Button) scene.lookup("#okButton");

        imageView.setImage(warning);

        okButton.setOnAction(e -> {
            choice = true;
            window.close();
        });
        cancelButton.setOnAction(e -> {
            choice = false;
            window.close();
        });

        window.initModality(Modality.APPLICATION_MODAL);
        window.initStyle(StageStyle.UNDECORATED);
        window.setTitle("Alerta");
        window.setScene(scene);
        mediaPlayer.play();
        window.showAndWait();

        return choice;
    }
}
