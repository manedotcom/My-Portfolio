public class main { 
    public static void main(String[] args) { 
        Cinema cinema = new Cinema("Ibn khaldoun", "Salembier");
        
        Room r1 = new Room(1, 100);
        Room r2 = new Room(2, 200);
        Room r3 = new Room(3, 300);

        cinema.add_room(r1);
        cinema.add_room(r2);
        cinema.add_room(r3);

        Movie m1 = new Movie("Movie1", 1970, "Director1", "Actor1.1 Actor1.2 Actor1.3", "Synopsis1");
        Movie m2 = new Movie("Movie2", 1980, "Director2", "Actor2.1 Actor2.2", "Synopsis2");
        Movie m3 = new Movie("Movie3", 1990, "Director3", "Actor3.1 Actor3.2 Actor3.3", "Synopsis3");

        Screening s11 = new Screening("04/03/2025", "18:00", "20:00", 11.49 , m1, 2);
        Screening s12 = new Screening("04/03/2025", "22:00", "00:00", 12.49 , m1, 100);
        cinema.add_screening(r1, s11);
        cinema.add_screening(r1, s12);

        Screening s21 = new Screening("05/03/2025", "18:00", "20:00", 13.99 , m2, 200);
        Screening s22 = new Screening("05/03/2025", "22:00", "00:00", 14.99 , m2, 200);
        cinema.add_screening(r2, s21);
        cinema.add_screening(r2, s22);

        Screening s31 = new Screening("06/03/2025", "18:00", "20:00", 15.25 , m3, 300);
        Screening s32 = new Screening("06/03/2025", "22:00", "00:00", 16.25 , m3, 300);
        cinema.add_screening(r3, s31);
        cinema.add_screening(r3, s32);

        // Question 2
        System.out.println(cinema.browse_scheduled_screenings());

        // QUESTION 3 *************************************************************************************************************
/* a */ Customer c1 = new Customer(1, 20);
/* b */ Customer c2 = new Customer(2, 30);
        cinema.add_customer(c1);
        cinema.add_customer(c2);

/* e */ cinema.reserve_seat(1, 1);
        cinema.reserve_seat(2, 1);

        cinema.verify_reservation(1);
        cinema.verify_reservation(2);

        Customer c3 = new Customer(3, 20);
        cinema.add_customer(c3);
/* c */ cinema.reserve_seat(3, 1);

/* d */ cinema.reserve_seat(5, 2);

/* f */ cinema.verify_reservation(5);
    }
}