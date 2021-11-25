package GPS.gpsproject.Sounds;

import javafx.scene.media.Media;

public interface BibliotecaSons {
    Media notificationSound = new Media(BibliotecaSons.class.getResource("/GPS/gpsproject/Sounds/finished-task.mp3").toString());
    Media errorSound = new Media(BibliotecaSons.class.getResource("/GPS/gpsproject/Sounds/unsure.mp3").toString());
}
