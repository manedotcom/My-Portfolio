package transport.control;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import transport.core.User;
import transport.core.UserType;
import transport.ui.MainApp;

import java.util.EnumSet;
import java.util.Set;

public class UserController {

    @FXML
    private TextField firstNameField;

    @FXML
    private TextField lastNameField;

    @FXML
    private TextField ageField;

    @FXML
    private CheckBox handicapCheckBox;

    @FXML
    private CheckBox partnerCheckBox;


    @FXML
    private ListView<User> userListView;

    @FXML
    public void initialize() {
        refreshUserList();
    }

    @FXML
    public void addUser() {
        String firstName = firstNameField.getText();
        String lastName = lastNameField.getText();
        String ageText = ageField.getText();

        if (firstName.isEmpty() || lastName.isEmpty() || ageText.isEmpty()) {
            showAlert("Error", "All fields are required.");
            return;
        }

        int age;
        try {
            age = Integer.parseInt(ageText);
            if (age <= 0) throw new NumberFormatException();
        } catch (NumberFormatException e) {
            showAlert("Error", "Age must be a positive integer.");
            return;
        }

        Set<UserType> types = EnumSet.noneOf(UserType.class);

        // Ajout automatique selon l'âge
        if (age < 25) types.add(UserType.JUNIOR);
        if (age > 65) types.add(UserType.SENIOR);

        // Ajout selon cases cochées
        if (handicapCheckBox.isSelected()) types.add(UserType.SOLIDARITY);
        if (partnerCheckBox.isSelected()) types.add(UserType.PARTNER);

        // Si aucun type, on ajoute PASSENGER par défaut
        if (types.isEmpty()) {
            types.add(UserType.PASSENGER);
        }

        User user = new User(firstName, lastName, types, age);
        MainApp.getDataManager().addUser(user);

        clearFields();
        refreshUserList();
    }

    private void refreshUserList() {
        userListView.getItems().clear();
        userListView.getItems().addAll(MainApp.getDataManager().getAllUsers());
    }

    private void clearFields() {
        firstNameField.clear();
        lastNameField.clear();
        ageField.clear();
        handicapCheckBox.setSelected(false);
        partnerCheckBox.setSelected(false);
    }

    private void showAlert(String title, String msg) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(msg);
        alert.showAndWait();
    }
}
