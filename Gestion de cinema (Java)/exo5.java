import java.util.concurrent.atomic.AtomicInteger;

class Cinema {
    private String name;
    private String address;
    private Room[] rooms = new Room[10];
    private Customer[] customers = new Customer[500];
    private Reservation[] reservations_list = new Reservation[500];


    public Cinema (String name, String address){
        this.name = name;
        this.address = address;
    }

    public void add_room(Room room){
        for (int i=0; i<10; i++){
            if (rooms[i]==null){
                rooms[i] = room;
                return;
            }
        }
        System.out.println("Can't add another room!");
    }

    public String browse_scheduled_screenings() {
        String chaine = "Displaying all scheduled screenings :";
        int i =0;
        while (rooms[i]!=null){
            chaine = chaine + rooms[i].display_screenings();
            i++;
        }
        return chaine;
    }

    public void reserve_seat(int customer_id, int screening_num) {
        int i =0;
        while (customers[i]!=null){
            if (customers[i].get_customer_id() == customer_id){
                for (int j=0; j<10; j++){
                    if (rooms[j]!=null){
                        if (check_seat_availability(screening_num, rooms[j])){
                            if (customers[i].get_num_attended()>25){
                                System.out.println("Reservation confirmed for customer with the number <"+customer_id+">, screening n°"+screening_num+" Price (with 5% discout): "+ rooms[j].get_price(screening_num)*0.95+ "$");
                            } else {
                                System.out.println("Reservation confirmed for customer with the number <"+customer_id+">, screening n°"+screening_num+" Price: "+ rooms[j].get_price(screening_num)+ "$");
                            }
                            customers[i].add_reservation(screening_num);
                            add_reservation();
                            rooms[j].decrement_seats(screening_num);
                        } else System.out.println("No seats available!");
                        return;
                    }
                }
            }
            i++;
        }
        System.out.println("Customer not found!");
    }

    public void verify_reservation(int reservation_num) {
        for (int i =0; i<500; i++){
            if (reservations_list[i]!=null && reservations_list[i].get_reservation_num() == reservation_num) {
                if (!reservations_list[i].is_used()){ //not used
                    reservations_list[i].set_to_used();
                    System.out.println("Valid Reservation!");
                } else System.out.println("Reservation already used!");//used
                return;
            }
        }
        System.out.println("Invalid Reservation!");
    }

    public void add_customer(Customer customer){
        for (int i=0; i<500; i++){
            if (customers[i]==null){
                customers[i] = customer;
                return;
            }
        }
        System.out.println("Can't add another customer!");
    }

    public void add_screening(Room room, Screening screening){
        for (int i=0; i<10; i++){
            if (rooms[i]==room){
                room.add_screening(screening);
                return;
            }
        }
        System.out.println("Can't add another screening!");
    }

    public boolean check_seat_availability(int screening_num, Room room){
        return room.check_seat_availability(screening_num);
    }

    public void add_reservation(){
        Reservation reservation = new Reservation();
        for (int i=0; i<500; i++){
            if (reservations_list[i] == null){
                reservations_list[i] = reservation;
                return;
            }
        }
    }
}

class Room {
    private int id;
    private int seating_capacity;
    private Screening[] scheduled_screenings = new Screening[50];

    public Room (int id, int seating_capacity){
        this.id = id;
        this.seating_capacity = seating_capacity;
    }

    public void add_screening(Screening screening){
        for (int i=0; i<50; i++){
            if (scheduled_screenings[i]==null){
                scheduled_screenings[i] = screening;
                return;
            }
        }
        System.out.println("Can't add another screening!");
    }

    public String display_screenings(){
        String chaine="\nRoom "+ id+ ":";
        int i =0;
        while (scheduled_screenings[i] != null){
            chaine = chaine + "\n\tScreening "+ scheduled_screenings[i].get_screening_num() + ":" + scheduled_screenings[i].get_movie().display_movie();
            i++;
        }
        return chaine;
    }

    public boolean check_seat_availability(int screening_num){
        boolean found = false;
        int i=0;
        while (i<50 && !found){
            if (scheduled_screenings[i]!=null && scheduled_screenings[i].get_screening_num()== screening_num){
                found = scheduled_screenings[i].seat_availability();
            }
            i++;
        }
        return found;
    }

    public double get_price(int screening_num){
        for (int i=0; i<50; i++){
            if (scheduled_screenings[i].get_screening_num()==screening_num){
                return scheduled_screenings[i].get_price();
            }
        }
        return 0;
    }

    public void decrement_seats(int screening_num){
        for (int i=0; i<50; i++){
            if (scheduled_screenings[i].get_screening_num()==screening_num){
                scheduled_screenings[i].decrement_seats();
                return;
            }
        }
        System.out.println("Screening not found!");
    }
}

class Screening {
    private int screening_num;
    private String date;
    private String start_time;
    private String end_time;
    private double ticket_price;
    private Movie shown_movie;
    private int available_seats;
    private static final AtomicInteger num_of_screenings = new AtomicInteger(1);

    public Screening (String date, String start_time, String end_time, double ticket_price, Movie shown_movie, int available_seats){
        this.screening_num = num_of_screenings.getAndIncrement();
        this.date = date;
        this.start_time = start_time;
        this.end_time = end_time;
        this.ticket_price = ticket_price;
        this.shown_movie = shown_movie;
        this.available_seats = available_seats;
    }

    public Movie get_movie(){return shown_movie;}

    public int get_screening_num(){return screening_num;}

    public boolean seat_availability(){
        if (available_seats>0) {
            return true;
        } else return false;
    }

    public double get_price(){return ticket_price;}

    public void decrement_seats(){
        available_seats--;
    }

}

class Movie {
    private String title;
    private int production_year;
    private String director_name;
    private String actors_list;
    private String synopsis;

    public Movie (String title, int production_year, String director_name, String actors_list, String synopsis){
        this.title = title;
        this.production_year = production_year;
        this.director_name = director_name;
        this.actors_list = actors_list;
        this.synopsis = synopsis;
    }

    public String display_movie(){
        return "\n\t\tTitle: " + title + "\n\t\tProduction year: " + production_year + "\n\t\tDirector's name: " + director_name + "\n\t\tActors: "+ actors_list + "\n\t\tSynopsis: "+ synopsis;
    }
}

class Customer {
    private int customer_id;
    private int num_screenings_attended;
    private int[] screenings_reserved = new int[50];
    //private boolean discount;

    public Customer (int customer_id, int num_screenings_attended){
        this.customer_id = customer_id;
        this.num_screenings_attended = num_screenings_attended;
        for (int i=0; i<50; i++){
            screenings_reserved[i] =0;
        }
    }

    public int get_customer_id(){return customer_id;}

    public int get_num_attended(){return num_screenings_attended;}

    public void add_reservation(int screening_num){
        for (int i=0; i<50; i++){
            if (screenings_reserved[i] == 0){
                screenings_reserved[i] = screening_num;
                return;
            }
        }
    }
}

class Reservation {
    private int reservation_num;
    private boolean used;
    private static int num_of_reservations=1;

    public Reservation (){
        this.reservation_num = num_of_reservations;
        num_of_reservations++;
        this.used = false;
    }

    public boolean is_used(){return used;}

    public int get_reservation_num(){return reservation_num;}

    public void set_to_used(){this.used = true;}
}
