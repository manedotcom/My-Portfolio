package transport.control;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import transport.core.*;
import transport.ui.MainApp;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import static java.lang.Integer.parseInt;

public class FareMediaController implements Initializable {
    
    @FXML
    private TextField fareIdField;
    
    @FXML
    private ComboBox<User> userComboBox;
    
    @FXML
    private RadioButton ticketRadioButton;
    
    @FXML
    private RadioButton cardRadioButton;
    
    @FXML
    private ToggleGroup fareTypeGroup;
    
    @FXML
    private ComboBox<PaymentMethod> paymentMethodComboBox;
    
    @FXML
    private Label priceLabel;
    
    @FXML
    private ListView<FareMedium> fareMediaListView;
    
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        // Initialize user combo box
        userComboBox.setItems(FXCollections.observableArrayList(MainApp.getDataManager().getAllUsers()));
        
        // Initialize payment method combo box
        paymentMethodComboBox.setItems(FXCollections.observableArrayList(PaymentMethod.values()));
        paymentMethodComboBox.getSelectionModel().selectFirst();
        
        // Set default selection for fare type
        ticketRadioButton.setSelected(true);
        
        // Load existing fare media
        refreshFareMediaList();
    }
    
    @FXML
    public void calculatePrice() {
        User selectedUser = userComboBox.getValue();

        if (selectedUser == null) {
            showAlert("Error", "Please select a user!");
            return;
        }

        double price;

        if (ticketRadioButton.isSelected()) {
            // Ticket price is fixed
            price = 50.0;
        } else {
            // Calculate card price based on user profile, catch eligibility
            try {
                NavigationCard tempCard = new NavigationCard(selectedUser, PaymentMethod.CASH);
                price = tempCard.getPrice();
            } catch (IllegalArgumentException e) {
                showAlert("Ineligible User", e.getMessage());
                price = 0.0;  // Or some default
            }
        }

        priceLabel.setText(String.format("Price: %.2f DA", price));
    }


    @FXML
    public void issueFareMedium() {
        // Validate fields
        if (userComboBox.getValue() == null ||
                paymentMethodComboBox.getValue() == null) {
            showAlert("Error", "All fields are required!");
            return;
        }

        User selectedUser = userComboBox.getValue();
        PaymentMethod paymentMethod = paymentMethodComboBox.getValue();

        FareMedium medium;

        if (ticketRadioButton.isSelected()) {
            medium = new Ticket(selectedUser, paymentMethod);
        } else {
            try {
                medium = new NavigationCard(selectedUser, paymentMethod);
            } catch (IllegalArgumentException e) {
                showAlert("Ineligible User", e.getMessage());
                return;  // stop here, do not add medium
            }
        }

        // Add fare medium to data manager
        MainApp.getDataManager().addFareMedium(medium);

        // Clear fields and refresh list
        clearFields();
        refreshFareMediaList();

        // Show success message
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success");
        alert.setHeaderText(null);
        alert.setContentText("Fare medium issued successfully with id " + medium.getId());
        alert.showAndWait();
    }

    private void refreshFareMediaList() {
        fareMediaListView.getItems().clear();
        fareMediaListView.getItems().addAll(MainApp.getDataManager().getAllFareMedia());
    }
    
    private void clearFields() {
        //fareIdField.clear();
        userComboBox.getSelectionModel().clearSelection();
        ticketRadioButton.setSelected(true);
        paymentMethodComboBox.getSelectionModel().selectFirst();
        priceLabel.setText("Price: 0.0 DA");
    }
    
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

}
