package transport.control;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import transport.core.FareMedium;
import transport.core.NavigationCard;
import transport.core.Ticket;
import transport.ui.MainApp;

import java.io.IOException;
import java.time.format.DateTimeFormatter;

public class ValidationController {
    
    @FXML
    private TextField validateIdField;
    
    @FXML
    private Label validationResultLabel;
    
    @FXML
    private TextArea validationDetailsArea;
    
    @FXML
    public void validateFareMedium() {
        int id = Integer.parseInt(validateIdField.getText());
        /*
        if (id ) {
            validationResultLabel.setText("Please enter a fare medium ID.");
            validationResultLabel.setTextFill(Color.RED);
            validationDetailsArea.clear();
            return;
        }*/
        
        FareMedium medium = MainApp.getDataManager().getFareMediumById(id);
        
        if (medium == null) {
            validationResultLabel.setText("Fare medium not found!");
            validationResultLabel.setTextFill(Color.RED);
            validationDetailsArea.clear();
            return;
        }
        
        boolean isValid = medium.isValid();
        
        if (isValid) {
            validationResultLabel.setText("VALID");
            validationResultLabel.setTextFill(Color.GREEN);
        } else {
            validationResultLabel.setText("INVALID");
            validationResultLabel.setTextFill(Color.RED);
        }
        
        // Display details
        StringBuilder details = new StringBuilder();
        details.append("Type: ").append(medium instanceof Ticket ? "Ticket" : "Navigation Card").append("\n");
        details.append("Owner: ").append(medium.getOwner().getFirstName()).append(" ").append(medium.getOwner().getLastName()).append("\n");
        details.append("Purchase Date: ").append(medium.getPurchaseDate().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"))).append("\n");
        
        if (medium instanceof NavigationCard) {
            NavigationCard card = (NavigationCard) medium;
            details.append("Expiration Date: ").append(card.getExpirationDate().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"))).append("\n");
            if (isValid) {
                details.append("Days Remaining: ").append(card.getRemainingDays()).append("\n");
            }
        }
        
        details.append("Payment Method: ").append(medium.getPaymentMethod()).append("\n");
        
        if (!isValid) {
            details.append("\nREASON: ");
            if (medium instanceof Ticket) {
                details.append("Tickets are only valid on the day of purchase.");
            } else {
                details.append("Navigation card has expired.");
            }
        }
        
        validationDetailsArea.setText(details.toString());
    }
    
    @FXML
    public void backToMainMenu(ActionEvent event) {
        try {
            Parent root = FXMLLoader.load(getClass().getResource("/transport/ui/WelcomeScreen.fxml"));
            Scene scene = new Scene(root);
            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
