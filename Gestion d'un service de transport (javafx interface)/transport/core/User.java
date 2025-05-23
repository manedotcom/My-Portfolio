package transport.core;

import java.io.Serializable;
import java.util.EnumSet;
import java.util.Set;

public class User implements Serializable {
    private static final long serialVersionUID = 1L;
    private static int counter = 1;

    private int id;
    private String firstName;
    private String lastName;
    private Set<UserType> types;
    private int age;

    public User(String firstName, String lastName, Set<UserType> types, int age) {
        this.id = counter++;
        this.firstName = firstName;
        this.lastName = lastName;
        this.types = types;
        this.age = age;
    }

    public int getId() {
        return id;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public Set<UserType> getTypes() {
        return types;
    }

    public void setTypes(Set<UserType> types) {
        this.types = types;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return firstName + " " + lastName + " (" + types + ")";
    }
}
