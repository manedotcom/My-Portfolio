package transport.core;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Map;
import java.util.Set;

public class NavigationCard extends FareMedium {
    private static final long serialVersionUID = 1L;
    private static final double BASE_CARD_PRICE = 5000.0;

    private LocalDate expirationDate;
    private double discountRate;

    public NavigationCard(User owner, PaymentMethod paymentMethod) {
        super(owner, paymentMethod);
        this.expirationDate = getPurchaseDate().plusYears(1);

        if (!hasEligibleReduction()) {
            throw new IllegalArgumentException("User is not eligible for a NavigationCard.");
        }

        calculateDiscountRate();
    }

    private boolean hasEligibleReduction() {
        int age = getOwner().getAge();
        Set<UserType> types = getOwner().getTypes();

        return age < 25 || age > 65 ||
                types.contains(UserType.SOLIDARITY) ||
                types.contains(UserType.PARTNER);
    }

    private void calculateDiscountRate() {
        int age = getOwner().getAge();
        Set<UserType> types = getOwner().getTypes();

        // Définir les taux de réduction (le taux est le multiplicateur du prix, plus bas = meilleure réduction)
        Map<UserType, Double> discounts = Map.of(
                UserType.JUNIOR, 0.7,       // 30% de réduction
                UserType.SENIOR, 0.75,      // 25% de réduction
                UserType.SOLIDARITY, 0.5,   // 50% de réduction
                UserType.PARTNER, 0.6       // 40% de réduction
        );

        // Ajout automatique selon l'âge (si non présent dans les types)
        if (age < 25) types.add(UserType.JUNIOR);
        if (age > 65) types.add(UserType.SENIOR);

        // Appliquer la réduction la plus avantageuse (taux minimal)
        discountRate = 1.0; // Sans réduction
        for (UserType type : types) {
            if (discounts.containsKey(type)) {
                double rate = discounts.get(type);
                if (rate < discountRate) {
                    discountRate = rate;
                }
            }
        }
    }

    @Override
    public double getPrice() {
        return BASE_CARD_PRICE * discountRate;
    }

    @Override
    public boolean isValid() {
        return !LocalDate.now().isAfter(expirationDate);
    }

    public LocalDate getExpirationDate() {
        return expirationDate;
    }

    public double getDiscountRate() {
        return discountRate;
    }

    public long getRemainingDays() {
        if (!isValid()) return 0;
        return ChronoUnit.DAYS.between(LocalDate.now(), expirationDate);
    }

    @Override
    public String toString() {
        return "Card #" + getId() + " - " + getOwner().getFirstName() + " " +
                getOwner().getLastName() + " - Expires: " + expirationDate +
                " - Valid: " + (isValid() ? "Yes (" + getRemainingDays() + " days remaining)" : "No") +
                " - Price: " + getPrice() + " DA";
    }
}
