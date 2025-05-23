package transport.control;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class WelcomeController {
    
    public void openUserManagement(ActionEvent event) {
        try {
            System.out.println("Opening User Management...");
            loadScreen(event, "UserManagement.fxml");
        } catch (Exception e) {
            System.err.println("Error opening User Management: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    public void openFareMediaManagement(ActionEvent event) {
        try {
            loadScreen(event, "FareMediaManagement.fxml");
        } catch (Exception e) {
            System.err.println("Error opening Fare Media Management: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    public void openFareValidation(ActionEvent event) {
        try {
            loadScreen(event, "FareValidation.fxml");
        } catch (Exception e) {
            System.err.println("Error opening Fare Validation: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    public void openComplaintManagement(ActionEvent event) {
        try {
            loadScreen(event, "ComplaintManagement.fxml");
        } catch (Exception e) {
            System.err.println("Error opening Complaint Management: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    public void exitApplication(ActionEvent event) {
        System.out.println("Exiting application...");
        System.exit(0);
    }
    
    private void loadScreen(ActionEvent event, String fxmlName) {
        try {
            // Try different ways to load the resource
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/transport/ui/" + fxmlName));
            
            // If that doesn't work, try an alternative
            if (loader.getLocation() == null) {
                System.out.println("First attempt failed, trying alternative...");
                loader = new FXMLLoader(getClass().getClassLoader().getResource("transport/ui/" + fxmlName));
            }
            
            // If that still doesn't work, try a third approach
            if (loader.getLocation() == null) {
                System.out.println("Second attempt failed, trying another alternative...");
                loader = new FXMLLoader(WelcomeController.class.getResource("/transport/ui/" + fxmlName));
            }
            
            Parent root = loader.load();
            Scene scene = new Scene(root);
            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(scene);
            stage.show();
            System.out.println("Screen loaded: " + fxmlName);
        } catch (IOException e) {
            System.err.println("Failed to load screen: " + fxmlName);
            e.printStackTrace();
        }
    }
}