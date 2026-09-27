import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class j24_MovieTicketBooking extends Application {

    // Movie prices
    final String[] movies    = {"Avengers", "Interstellar", "Inception", "The Batman"};
    final double[] prices    = {250.0,       300.0,          280.0,       260.0};

    final String[] showtimes = {"10:00 AM", "1:00 PM", "4:00 PM", "7:00 PM", "10:00 PM"};

    // UI Controls (declared here so reset() can access them)
    ComboBox<String> movieBox;
    ComboBox<String> showtimeBox;
    Spinner<Integer> ticketSpinner;
    Label priceLabel;
    Label totalLabel;
    Label confirmLabel;

    @Override
    public void start(Stage stage) {

        // ── Title ──────────────────────────────────────────
        Label title = new Label("Movie Ticket Booking");
        title.setFont(Font.font("Arial", 22));
        title.setStyle("-fx-font-weight: bold;");

        // ── Movie Selection ────────────────────────────────
        Label movieLabel = new Label("Select Movie:");
        movieBox = new ComboBox<>();
        movieBox.getItems().addAll(movies);
        movieBox.setPromptText("-- Choose Movie --");
        movieBox.setPrefWidth(220);
        movieBox.setOnAction(e -> updatePrice());

        // ── Showtime Selection ─────────────────────────────
        Label showtimeLabel = new Label("Select Showtime:");
        showtimeBox = new ComboBox<>();
        showtimeBox.getItems().addAll(showtimes);
        showtimeBox.setPromptText("-- Choose Showtime --");
        showtimeBox.setPrefWidth(220);

        // ── Ticket Count ───────────────────────────────────
        Label ticketLabel = new Label("Number of Tickets:");
        ticketSpinner = new Spinner<>(1, 10, 1);
        ticketSpinner.setPrefWidth(220);
        ticketSpinner.valueProperty().addListener((obs, oldVal, newVal) -> updateTotal());

        // ── Price Display ──────────────────────────────────
        priceLabel = new Label("Price per Ticket:  ₹ --");
        priceLabel.setStyle("-fx-text-fill: #555;");

        totalLabel = new Label("Total Cost:  ₹ --");
        totalLabel.setFont(Font.font("Arial", 15));
        totalLabel.setStyle("-fx-font-weight: bold; -fx-text-fill: #2a7a2a;");

        // ── Confirmation Message ───────────────────────────
        confirmLabel = new Label("");
        confirmLabel.setStyle("-fx-text-fill: #1a6bbf; -fx-font-weight: bold;");
        confirmLabel.setWrapText(true);

        // ── Buttons ────────────────────────────────────────
        Button confirmBtn = new Button("Confirm Booking");
        Button resetBtn   = new Button("Reset");
        Button exitBtn    = new Button("Exit");

        confirmBtn.setPrefWidth(140);
        resetBtn.setPrefWidth(90);
        exitBtn.setPrefWidth(90);

        confirmBtn.setStyle("-fx-background-color: #2a7a2a; -fx-text-fill: white;");
        resetBtn.setStyle("-fx-background-color: #e07b00; -fx-text-fill: white;");
        exitBtn.setStyle("-fx-background-color: #c0392b; -fx-text-fill: white;");

        confirmBtn.setOnAction(e -> confirmBooking());
        resetBtn.setOnAction(e -> reset());
        exitBtn.setOnAction(e -> stage.close());

        HBox buttonRow = new HBox(12, confirmBtn, resetBtn, exitBtn);
        buttonRow.setAlignment(Pos.CENTER);

        // ── Form Grid ──────────────────────────────────────
        GridPane grid = new GridPane();
        grid.setHgap(14);
        grid.setVgap(14);
        grid.setPadding(new Insets(16, 20, 16, 20));

        grid.add(movieLabel,    0, 0); grid.add(movieBox,      1, 0);
        grid.add(showtimeLabel, 0, 1); grid.add(showtimeBox,   1, 1);
        grid.add(ticketLabel,   0, 2); grid.add(ticketSpinner, 1, 2);
        grid.add(priceLabel,    0, 3); GridPane.setColumnSpan(priceLabel, 2);
        grid.add(totalLabel,    0, 4); GridPane.setColumnSpan(totalLabel, 2);

        // ── Main Layout ────────────────────────────────────
        VBox root = new VBox(16);
        root.setPadding(new Insets(20));
        root.setAlignment(Pos.TOP_CENTER);
        root.getChildren().addAll(title, new Separator(), grid, buttonRow, confirmLabel);

        Scene scene = new Scene(root, 420, 370);
        stage.setTitle("Movie Ticket Booking System");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
    }

    // Called when movie is selected — show price per ticket
    void updatePrice() {
        int idx = movieBox.getSelectionModel().getSelectedIndex();
        if (idx >= 0) {
            priceLabel.setText("Price per Ticket:  ₹ " + prices[idx]);
            updateTotal();
        }
    }

    // Recalculate total whenever movie or ticket count changes
    void updateTotal() {
        int idx = movieBox.getSelectionModel().getSelectedIndex();
        if (idx >= 0) {
            double total = prices[idx] * ticketSpinner.getValue();
            totalLabel.setText("Total Cost:  ₹ " + total);
        }
    }

    // Confirm booking — show summary message
    void confirmBooking() {
        if (movieBox.getValue() == null) {
            confirmLabel.setStyle("-fx-text-fill: red; -fx-font-weight: bold;");
            confirmLabel.setText("Please select a movie.");
            return;
        }
        if (showtimeBox.getValue() == null) {
            confirmLabel.setStyle("-fx-text-fill: red; -fx-font-weight: bold;");
            confirmLabel.setText("Please select a showtime.");
            return;
        }

        int idx     = movieBox.getSelectionModel().getSelectedIndex();
        double total = prices[idx] * ticketSpinner.getValue();

        confirmLabel.setStyle("-fx-text-fill: #1a6bbf; -fx-font-weight: bold;");
        confirmLabel.setText(
            "Booking Confirmed!\n" +
            "Movie: "    + movieBox.getValue()    + "\n" +
            "Showtime: " + showtimeBox.getValue() + "\n" +
            "Tickets: "  + ticketSpinner.getValue() + "  |  Total: ₹" + total
        );
    }

    // Reset all fields
    void reset() {
        movieBox.getSelectionModel().clearSelection();
        movieBox.setPromptText("-- Choose Movie --");
        showtimeBox.getSelectionModel().clearSelection();
        showtimeBox.setPromptText("-- Choose Showtime --");
        ticketSpinner.getValueFactory().setValue(1);
        priceLabel.setText("Price per Ticket:  ₹ --");
        totalLabel.setText("Total Cost:  ₹ --");
        confirmLabel.setText("");
    }

    public static void main(String[] args) {
        launch(args);
    }
}
