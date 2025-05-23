package transport.core;

import java.io.Serializable;
import java.time.LocalDateTime;

public class Complaint implements Serializable {
    private static final long serialVersionUID = 1L;
    private static int num = 0;
    private int id;
    private User reporter;
    private ComplaintType type;
    private String description;
    private String concernedEntity; // Station or transport method name
    private LocalDateTime dateTime;

    public Complaint(User reporter, ComplaintType type, String description, String concernedEntity) {
        num++;
        this.id = num;
        this.reporter = reporter;
        this.type = type;
        this.description = description;
        this.concernedEntity = concernedEntity;
        this.dateTime = LocalDateTime.now();
    }

    // Getters
    public int getId() {
        return id;
    }

    public User getReporter() {
        return reporter;
    }

    public ComplaintType getType() {
        return type;
    }

    public String getDescription() {
        return description;
    }

    public String getConcernedEntity() {
        return concernedEntity;
    }

    public LocalDateTime getDateTime() {
        return dateTime;
    }

    @Override
    public String toString() {
        return "Complaint #" + id + " - Type: " + type +
                " - Entity: " + concernedEntity +
                " - By: " + reporter.getFirstName() + " " + reporter.getLastName() +
                " - Date: " + dateTime;
    }
}
