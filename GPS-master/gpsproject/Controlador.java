package GPS.gpsproject;

import GPS.Modelo.*;
import GPS.Modelo.Notification.Notification;
import GPS.gpsproject.calendar.FullCalendarView;
import GPS.gpsproject.images.BibliotecaImagens;
import javafx.application.Platform;
import javafx.beans.property.BooleanProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.chart.PieChart;
import javafx.scene.control.*;
import javafx.scene.control.cell.CheckBoxListCell;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.util.Callback;

import java.io.IOException;
import java.time.Month;
import java.time.YearMonth;
import java.util.ArrayList;
import java.util.List;

import static GPS.gpsproject.calendar.DateUtils.noFutureDates;

public class Controlador implements BibliotecaImagens, Constantes {
    public ListView list;
    public Button updateAll;
    public Button addButton;
    //Visão Geral
    public VBox left;
    public VBox right;
    public TitledPane detailsvehicle;
    public TextArea detailsvehicletext;
    public PieChart pie;
    public TitledPane events;
    public ListView eventslist;
    public Button eliminateButton;
    public Button categoria;
    public Button mensais;
    public Button gerais;
    public Button mecanica;
    public Button reparacoes;
    public Button manutencoes;
    public Button addEvento;
    //Editar detalhes
    public VBox detalhes;
    public Button guardaalteracoes;
    public TextField nome;
    public TextField modelo;
    public TextField matricula;
    public TextField tipo;
    public DatePicker registomatricula;
    public TextField seguradora;
    public TextField tiposeguro;
    public DatePicker registoseguro;
    public TextField kmmensais;
    public TextField kmreais;
    //Calendario Geral
    public HBox calendarbox;
    public TextArea detailsdia;

    private Frota frota;
    private Notifica notifica;
    private Veiculo veiculoSelecionado;
    private boolean monthly;

    @FXML
    public void initialize() {
        setGraphics();

        registoseguro.setDayCellFactory(noFutureDates);
        registomatricula.setDayCellFactory(noFutureDates);

        frota = new Frota();

        notifica = new Notifica(frota.getVeiculos(), this);
        notifica.start();

        startCalendar();

        noneSelected();
        initializeList();
        initializeListeners();
    }

    private void startCalendar() {
        FullCalendarView calendarView = new FullCalendarView(YearMonth.now(), detailsdia, frota.getEventosTotal());
        calendarbox.getChildren().setAll(calendarView.getView());
        HBox.setHgrow(calendarView.getView(), Priority.ALWAYS);
    }

    private void initializeFields() {
        detailsvehicletext.setText(veiculoSelecionado.toString());

        nome.setText(veiculoSelecionado.getNome());
        matricula.setText(veiculoSelecionado.getMatricula());
        modelo.setText(veiculoSelecionado.getModelo());
        registomatricula.setValue(veiculoSelecionado.getDataRegistoMatricula());
        if (veiculoSelecionado instanceof Ligeiro) tipo.setText(String.valueOf(TipoVeiculo.LIGEIRO));
        if (veiculoSelecionado instanceof Pesado) tipo.setText(String.valueOf(TipoVeiculo.PESADO));
        if (veiculoSelecionado instanceof Motociclo) tipo.setText(String.valueOf(TipoVeiculo.MOTOCICLO));
        seguradora.setText(veiculoSelecionado.getSeguro().getSeguradora());
        tiposeguro.setText(veiculoSelecionado.getSeguro().getTipo());
        kmreais.setText(String.valueOf(veiculoSelecionado.getKmReais()));
        kmmensais.setText(String.valueOf(veiculoSelecionado.getKmMensais()));
        registoseguro.setValue(veiculoSelecionado.getSeguro().getDataRegisto());
    }

    private void initializeList() {
        list.getItems().setAll(frota.getNomesVeiculos());
        if(veiculoSelecionado != null) list.getSelectionModel().select(veiculoSelecionado.getNome());

        eventslist.setCellFactory(CheckBoxListCell.forListView((Callback<Evento, ObservableValue<Boolean>>) param -> {
            BooleanProperty observable = new SimpleBooleanProperty();
            if(param.isCheck()) observable.setValue(true);
            observable.addListener(((observable1, oldValue, newValue) -> {
                if (!param.isCheck()) {
                    veiculoSelecionado.realizaEvento(param, getCusto());
                    eventslist.setItems(FXCollections.observableArrayList(veiculoSelecionado.getEventos()));
                    updatePie();
                }
            }));
            return observable;
        }));

        list.setCellFactory(param -> new ListCell<String>() {
            private ImageView imageView = new ImageView();
            @Override
            public void updateItem(String name, boolean empty) {
                super.updateItem(name, empty);
                if (empty) {
                    setText(null);
                    setGraphic(null);
                } else {
                    if (frota.pesquisaVeiculo(name) instanceof Ligeiro) {
                        imageView.setImage(car);
                    }
                    if (frota.pesquisaVeiculo(name) instanceof Motociclo) {
                        imageView.setImage(moto);
                    }
                    if (frota.pesquisaVeiculo(name) instanceof Pesado) {
                        imageView.setImage(truck);
                    }
                    setText(name);
                    setGraphic(imageView);
                }
            }
        });
    }

    private void updatePie() {
        ObservableList<PieChart.Data> pieData = FXCollections.observableArrayList();
        double[] custosMeses = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        if (monthly) {
            for (Evento e : veiculoSelecionado.getEventos()) {
                custosMeses[e.getData().getMonthValue() - 1] += e.getCusto();
            }

            for (Month m : Month.values()) {
                if (custosMeses[m.getValue() - 1] > 0) {
                    pieData.add(new PieChart.Data(m.toString(), custosMeses[m.getValue() - 1]));
                }
            }
        } else {
            double[] custos = new double[4];

            for (Evento e : veiculoSelecionado.getEventos()) {
                switch (e.getTipoEvento()) {
                    case MECANICA:
                        custos[0] += e.getCusto();
                        break;
                    case REPARACAO:
                        custos[1] += e.getCusto();
                        break;
                    case OBRIGACOES:
                        custos[2] += e.getCusto();
                        break;
                    case MANUTENCOES:
                        custos[3] += e.getCusto();
                        break;
                }
            }

            if (custos[0] > 0) pieData.add(new PieChart.Data("Mecânica", custos[0]));
            if (custos[1] > 0) pieData.add(new PieChart.Data("Reparação", custos[1]));
            if (custos[2] > 0) pieData.add(new PieChart.Data("Obrigações", custos[2]));
            if (custos[3] > 0) pieData.add(new PieChart.Data("Manutenções", custos[3]));
        }

        pie.setData(pieData);
        pie.setLabelsVisible(false);
        try {
            frota.guardarFrotaBD();
        } catch (IOException ignored) {}
    }

    private double getCusto() {
        return Custo.display();
    }

    private void initializeListeners() {
        list.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) -> setVeiculo((String) newValue));
    }

    private void setVeiculo(String veiculo) {
        if(frota.pesquisaVeiculo(veiculo) == null) {
            noneSelected();
            return;
        }
        veiculoSelecionado = frota.pesquisaVeiculo(veiculo);
        initializeFields();
        eventslist.getItems().setAll(veiculoSelecionado.getEventos());
        updatePie();
        vehicleSelected();
    }

    private void setGraphics() {
        eliminateButton.setGraphic(new ImageView(cross));
        addButton.setGraphic(new ImageView(plus));
        updateAll.setGraphic(new ImageView(refresh));
        guardaalteracoes.setGraphic(new ImageView(check));
        addEvento.setGraphic(new ImageView(plus));
        addEvento.setTooltip(new Tooltip("Adicionar evento"));
    }

    private void noneSelected() {
        left.setVisible(false);

        detalhes.setVisible(false);

        events.setVisible(false);
        gerais.setVisible(false);
        mecanica.setVisible(false);
        reparacoes.setVisible(false);
        manutencoes.setVisible(false);
        addEvento.setVisible(false);
        eliminateButton.setVisible(false);
    }

    private void vehicleSelected() {
        left.setVisible(true);

        detalhes.setVisible(true);

        events.setVisible(true);
        gerais.setVisible(true);
        mecanica.setVisible(true);
        reparacoes.setVisible(true);
        manutencoes.setVisible(true);
        addEvento.setVisible(true);
        eliminateButton.setVisible(true);
    }

    @FXML
    private void onGuardaAlteracoes() {
        if (!everyFieldIsFilled()) {
            Alert.display("Alerta", "Não é permitido guardar campos vazios!");
            return;
        }

        if (!everyFieldIsValid()) {
            Alert.display("Alerta", "Verifique se os campos possuem dados válidos!\n" +
                    "- Kilómetros reais entre 1 e 1,000,000\n" +
                    "- Kilómetros mensais entre 1 e 10,000");
            return;
        }
        veiculoSelecionado.altera(nome.getText(),
                seguradora.getText(),
                tiposeguro.getText(),
                registoseguro.getValue(),
                Integer.parseInt(kmreais.getText()),
                Integer.parseInt(kmmensais.getText()));

        try {
            frota.guardarFrotaBD();
        } catch (IOException ignore) {}
        initializeList();
    }

    private boolean everyFieldIsValid() {
        try {
            int kms = Integer.parseInt(kmmensais.getText());
            int kmsr = Integer.parseInt(kmreais.getText());

            if(kms <= 0 || kmsr <= 0 || kms > 10000 || kmsr > 1000000)
                return false;
        } catch(NumberFormatException | NullPointerException e) {
            return false;
        }
        return true;
    }

    private boolean everyFieldIsFilled() {
        return !nome.getText().trim().equals("") &&
                !modelo.getText().trim().equals("") &&
                !tipo.getText().trim().equals("") &&
                registomatricula.getValue() != null &&
                !seguradora.getText().trim().equals("") &&
                !tiposeguro.getText().trim().equals("") &&
                registoseguro.getValue() != null &&
                !kmreais.getText().trim().equals("") &&
                !kmmensais.getText().trim().equals("");
    }

    public void onAddButton() {
        Veiculo adicionar = Adicionar.display();

        if (adicionar != null) {
            frota.RegistaVeiculo(adicionar);
            list.setItems(FXCollections.observableArrayList(frota.getNomesVeiculos()));
            startCalendar();
        }
    }

    public void onCategoria() {
        monthly = false;
        updatePie();
    }

    public void onMensais() {
        monthly = true;
        updatePie();
    }

    public void onGerais() {
        eventslist.setItems(FXCollections.observableArrayList(veiculoSelecionado.getEventos()));
    }

    public void onMecanica() {
        List<Evento> tmpList = new ArrayList<>();

        for (Evento e : veiculoSelecionado.getEventos()) {
            if(e.getTipoEvento() == TipoEvento.MECANICA)
                tmpList.add(e);
        }

        eventslist.setItems(FXCollections.observableArrayList(tmpList));
    }

    public void onReparacoes() {
        List<Evento> tmpList = new ArrayList<>();

        for (Evento e : veiculoSelecionado.getEventos()) {
            if(e.getTipoEvento() == TipoEvento.REPARACAO)
                tmpList.add(e);
        }

        eventslist.setItems(FXCollections.observableArrayList(tmpList));
    }

    public void onManutencoes() {
        List<Evento> tmpList = new ArrayList<>();

        for (Evento e : veiculoSelecionado.getEventos()) {
            if(e.getTipoEvento() == TipoEvento.MANUTENCOES)
                tmpList.add(e);
        }

        eventslist.setItems(FXCollections.observableArrayList(tmpList));
    }

    public void onEliminate() {
        if(Confirm.display()) {
            frota.eliminaVeiculo(veiculoSelecionado.getMatricula());

            list.setItems(FXCollections.observableArrayList(frota.getNomesVeiculos()));
        }

        try {
            frota.guardarFrotaBD();
        } catch (IOException e) {
            System.exit(3);
        }
    }

    public void onAddEvento() {
        notifica.setStop(true);
        AdicionaEvento.display(veiculoSelecionado);

        eventslist.setItems(FXCollections.observableArrayList(veiculoSelecionado.getEventos()));
        try {
            frota.guardarFrotaBD();
        } catch (IOException e) {
            e.printStackTrace();
        }

        startCalendar();
        notifica = new Notifica(frota.getVeiculos(), this);
        notifica.start();
    }

    public void onUpdateAll() {
        Altera.display(frota);
        setVeiculo(veiculoSelecionado.getNome());
    }

    public void sendNotification(String title, String description) {
        Platform.runLater(() -> Notification.sendNotification(title, description));

        try {
            frota.guardarFrotaBD();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void sendLateNotification(String title, String description) {
        Platform.runLater(() -> Notification.sendLateNotification(title, description));

        try {
            frota.guardarFrotaBD();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void resetNotifications() {
        for (Veiculo v : frota.getVeiculos()) {
            for (Evento e : v.getEventos()) {
                if (!e.isCheck()) {
                    e.setNotificado(false);
                    e.setNotificadoAtraso(false);
                }
            }
        }

        try {
            frota.guardarFrotaBD();
        } catch (IOException e) {
            System.exit(1);
        }
    }
}