package transport.ui;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import java.io.IOException;

public class MainLayoutController {
    @FXML private StackPane contentPane;

    @FXML
    private void loadUserManagement() { loadView("/transport/ui/UserManagement.fxml"); }

    @FXML
    private void loadFareMediaManagement() { loadView("/transport/ui/FareMediaManagement.fxml"); }

    @FXML
    private void loadFareValidation() { loadView("/transport/ui/FareValidation.fxml"); }

    @FXML
    private void loadComplaintManagement() { loadView("/transport/ui/ComplaintManagement.fxml"); }

    @FXML
    private void exitApp() { System.exit(0); }

    @FXML
    private void showWelcome() {
        contentPane.getChildren().clear();

        Text welcomeText = new Text("Welcome to ESI-RUN");
        welcomeText.setStyle("-fx-font-size: 28px; -fx-fill: #34495e; -fx-font-weight: bold;");

        Text subText = new Text("Station Management System");
        subText.setStyle("-fx-font-size: 18px; -fx-fill: #7f8c8d;");

        VBox welcomeContent = new VBox(20, welcomeText, subText);
        welcomeContent.setAlignment(Pos.CENTER);

        contentPane.getChildren().add(welcomeContent);
    }

    private void loadView(String fxmlPath) {
        try {
            Parent view = FXMLLoader.load(getClass().getResource(fxmlPath));
            contentPane.getChildren().clear();
            contentPane.getChildren().add(view);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}