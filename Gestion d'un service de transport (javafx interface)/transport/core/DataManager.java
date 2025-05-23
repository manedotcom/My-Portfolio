package transport.core;

import java.io.*;
import java.util.*;

public class DataManager {
    private List<User> users;
    private List<FareMedium> fareMedia;
    private List<Complaint> complaints;
    private Map<String, Integer> complaintCountByEntity;

    private static final String DATA_FILE = "esi_run_data.ser";

    public DataManager() {
        users = new ArrayList<>();
        fareMedia = new ArrayList<>();
        complaints = new ArrayList<>();
        complaintCountByEntity = new HashMap<>();

        // Try to load saved data
        loadData();
    }

    // User management
    public void addUser(User user) {
        users.add(user);
        saveData();
    }

    public User getUserById(int id) {
        for (User user : users) {
            if (user.getId() == id) {
                return user;
            }
        }
        return null;
    }

    public List<User> getAllUsers() {
        return new ArrayList<>(users);
    }

    // Fare medium management
    public void addFareMedium(FareMedium medium) {
        fareMedia.add(medium);
        Collections.sort(fareMedia); // Sort by purchase date (most recent first)
        saveData();
    }

    public FareMedium getFareMediumById(int id) {
        for (FareMedium medium : fareMedia) {
            if (medium.getId() == id) {
                return medium;
            }
        }
        return null;
    }

    public List<FareMedium> getAllFareMedia() {
        Collections.sort(fareMedia); // Ensure sorting
        return new ArrayList<>(fareMedia);
    }

    // Complaint management
    public void addComplaint(Complaint complaint) {
        complaints.add(complaint);

        // Update complaint count for the concerned entity
        String entity = complaint.getConcernedEntity();
        complaintCountByEntity.put(entity, complaintCountByEntity.getOrDefault(entity, 0) + 1);

        saveData();
    }

    public List<Complaint> getAllComplaints() {
        return new ArrayList<>(complaints);
    }

    public boolean isEntitySuspended(String entity) {
        return complaintCountByEntity.getOrDefault(entity, 0) > 3;
    }

    // Data persistence
    public void saveData() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(DATA_FILE))) {
            oos.writeObject(users);
            oos.writeObject(fareMedia);
            oos.writeObject(complaints);
            oos.writeObject(complaintCountByEntity);
            System.out.println("Data saved successfully.");
        } catch (IOException e) {
            System.err.println("Error saving data: " + e.getMessage());
        }
    }

    @SuppressWarnings("unchecked")
    public void loadData() {
        File file = new File(DATA_FILE);
        if (!file.exists()) {
            System.out.println("No saved data found.");
            return;
        }

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
            users = (List<User>) ois.readObject();
            fareMedia = (List<FareMedium>) ois.readObject();
            complaints = (List<Complaint>) ois.readObject();
            complaintCountByEntity = (Map<String, Integer>) ois.readObject();
            System.out.println("Data loaded successfully.");
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error loading data: " + e.getMessage());
            // Initialize with empty collections if error occurs
            users = new ArrayList<>();
            fareMedia = new ArrayList<>();
            complaints = new ArrayList<>();
            complaintCountByEntity = new HashMap<>();
        }
    }
}