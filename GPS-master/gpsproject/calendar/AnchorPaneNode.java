package GPS.gpsproject.calendar;

import GPS.Modelo.Evento;
import javafx.scene.Node;
import javafx.scene.control.TextArea;
import javafx.scene.layout.AnchorPane;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Create an anchor pane that can store additional data.
 */
public class AnchorPaneNode extends AnchorPane {

    // Date associated with this pane
    private LocalDate date;
    private List<Evento> eventos;
    private TextArea detailsdia;
    /**
     * Create a anchor pane node. Date is not assigned in the constructor.
     * @param children children of the anchor pane
     */
    public AnchorPaneNode(TextArea detailsdia, Node... children) {
        super(children);

        this.eventos = new ArrayList<>();
        this.detailsdia = detailsdia;
        // Add action handler for mouse clicked
        this.setOnMouseClicked(e -> setDetails());
    }

    private void setDetails() {
        if(eventos.size() == 0) {
            detailsdia.setText("Dia sem eventos");
            return;
        }

        detailsdia.setText(detalhaEventos());
    }

    private String detalhaEventos() {
        String text = "";

        eventos = eventos.stream().distinct().collect(Collectors.toList());

        for(Evento e : eventos) {
            text += e.toString() + "\n";
        }

        return text;
    }

    public LocalDate getDate() {
        return date;
    }

    public void addEvento(Evento e) {
        eventos.add(e);
    }

    public void setDate(LocalDate date) {
        this.date = date;
        eventos = new ArrayList<>();
    }
}
