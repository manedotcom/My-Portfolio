package transport.core;

import java.io.Serializable;
import java.time.LocalDate;

public abstract class FareMedium implements Serializable, Comparable<FareMedium> {
    private static final long serialVersionUID = 1L;
    private static int num = 0;
    private int id;
    private User owner;
    private LocalDate purchaseDate;
    private PaymentMethod paymentMethod;

    public FareMedium(User owner, PaymentMethod paymentMethod) {
        num++;
        this.id = num;
        this.owner = owner;
        this.purchaseDate = LocalDate.now();
        this.paymentMethod = paymentMethod;
    }

    // Getters and setters
    public int getId() {
        return id;
    }

    public User getOwner() {
        return owner;
    }

    public LocalDate getPurchaseDate() {
        return purchaseDate;
    }

    public PaymentMethod getPaymentMethod() {
        return paymentMethod;
    }

    public void setPaymentMethod(PaymentMethod paymentMethod) {
        this.paymentMethod = paymentMethod;
    }

    // Abstract methods
    public abstract double getPrice();
    public abstract boolean isValid();

    @Override
    public int compareTo(FareMedium other) {
        // Sort by purchase date descending (most recent first)
        return other.purchaseDate.compareTo(this.purchaseDate);
    }
}
