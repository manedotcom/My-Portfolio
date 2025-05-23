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
import transport.core.Complaint;
import transport.core.ComplaintType;
import transport.core.User;
import transport.ui.MainApp;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ComplaintController implements Initializable {
    
    @FXML
    private TextField complaintIdField;
    
    @FXML
    private ComboBox<User> reporterComboBox;
    
    @FXML
    private ComboBox<ComplaintType> complaintTypeComboBox;
    
    @FXML
    private TextField entityField;
    
    @FXML
    private TextArea descriptionArea;
    
    @FXML
    private ListView<Complaint> complaintsListView;
    
    @FXML
    private Label suspensionLabel;
    
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        // Initialize reporter combo box
        reporterComboBox.setItems(FXCollections.observableArrayList(MainApp.getDataManager().getAllUsers()));
        
        // Initialize complaint type combo box
        complaintTypeComboBox.setItems(FXCollections.observableArrayList(ComplaintType.values()));
        complaintTypeComboBox.getSelectionModel().selectFirst();
        
        // Load existing complaints
        refreshComplaintsList();
    }
    
    @FXML
    public void registerComplaint() {
        // Validate fields
        if (reporterComboBox.getValue() == null ||
            complaintTypeComboBox.getValue() == null || entityField.getText().isEmpty() ||
            descriptionArea.getText().isEmpty()) {
            showAlert("Error", "All fields are required!");
            return;
        }
        
        // Create and add complaint
        Complaint complaint = new Complaint(
            //complaintIdField.getText(),
            reporterComboBox.getValue(),
            complaintTypeComboBox.getValue(),
            descriptionArea.getText(),
            entityField.getText()
        );
        
        MainApp.getDataManager().addComplaint(complaint);
        
        // Clear fields and refresh list
        clearFields();
        refreshComplaintsList();
        
        // Check if entity should be suspended
        checkSuspension();
    }
    
    private void checkSuspension() {
        for (Complaint complaint : MainApp.getDataManager().getAllComplaints()) {
            String entity = complaint.getConcernedEntity();
            if (MainApp.getDataManager().isEntitySuspended(entity)) {
                suspensionLabel.setText("WARNING: " + entity + " has been suspended due to multiple complaints!");
                return;
            }
        }
        suspensionLabel.setText("");
    }
    
    private void refreshComplaintsList() {
        complaintsListView.getItems().clear();
        complaintsListView.getItems().addAll(MainApp.getDataManager().getAllComplaints());
    }
    
    private void clearFields() {
        //complaintIdField.clear();
        reporterComboBox.getSelectionModel().clearSelection();
        complaintTypeComboBox.getSelectionModel().selectFirst();
        entityField.clear();
        descriptionArea.clear();
    }
    
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
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