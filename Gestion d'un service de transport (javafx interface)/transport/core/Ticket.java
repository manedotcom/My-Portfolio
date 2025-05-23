package transport.core;

import java.time.LocalDate;

public class Ticket extends FareMedium {
    private static final long serialVersionUID = 1L;
    private static final double TICKET_PRICE = 50.0;

    public Ticket(User owner, PaymentMethod paymentMethod) {
        super(owner, paymentMethod);
    }

    @Override
    public double getPrice() {
        return TICKET_PRICE;
    }

    @Override
    public boolean isValid() {
        // Ticket is valid only on the purchase date
        return getPurchaseDate().equals(LocalDate.now());
    }

    @Override
    public String toString() {
        return "Ticket #" + getId() + " - " + getOwner().getFirstName() + " " +
                getOwner().getLastName() + " - " + getPurchaseDate() +
                " - Valid: " + (isValid() ? "Yes" : "No");
    }
}