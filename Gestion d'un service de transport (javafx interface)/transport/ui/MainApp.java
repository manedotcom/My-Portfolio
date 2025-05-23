package transport.ui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import transport.core.DataManager;

public class MainApp extends Application {
    
    private static DataManager dataManager;
    
    @Override
    public void start(Stage primaryStage) throws Exception {
        dataManager = new DataManager();
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("MainLayout.fxml"));
            Parent root = loader.load();
            primaryStage.setScene(new Scene(root, 800, 600));
            primaryStage.setTitle("Transport System Manager");
            primaryStage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static DataManager getDataManager() {
        return dataManager;
    }
    
    public static void main(String[] args) {
        // Add this to see any startup errors
        try {
            launch(args);
        } catch (Exception e) {
            System.err.println("Application failed to start: " + e.getMessage());
            e.printStackTrace();
        }
    }
}