package GPS.gpsproject;

import com.sun.glass.ui.Screen;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.io.IOException;

import static GPS.gpsproject.images.BibliotecaImagens.car;

public class GpsProject extends Application {

    @Override
    public void start(final Stage stage) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("FXML/VC.fxml"));
        Parent root = loader.load();
        Controlador controlador = loader.getController();
        int sceneWidth = 2 * Screen.getMainScreen().getWidth() / 3;
        int sceneHeight = 2 * Screen.getMainScreen().getHeight() / 3;
        Scene scene = new Scene(root, sceneWidth, sceneHeight);

        stage.setTitle("Vehicle Companion");
        stage.getIcons().add(car);
        stage.setScene(scene);
        stage.setOnCloseRequest(event -> {
            controlador.resetNotifications();
            System.exit(0);
        });
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
