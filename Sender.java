package Seaport;

import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;


public class Sender {
    private String name;
    private String surname;
    private String peselNumber;
    private String address;

    public Sender(String name, String surname, String peselNumber, String address) {
        this.name = name;
        this.surname = surname;
        this.peselNumber = peselNumber;
        this.address = address;
    }

    public void getDateOfBirth() throws IOException {
        String date = peselNumber.substring(0, 6);
        String prefix = Integer.parseInt(peselNumber.substring(0, 2)) > 23 ? "19" : "20";
        String date2 = prefix + date.substring(0, 2) + "-" + date.substring(2, 4) + "-" + date.substring(4, 6);
        LocalDate localDate = LocalDate.parse(date2);
        FileWriter writer = new FileWriter("Seaport/dateOfBirths.txt", true);
        writer.write(String.valueOf(localDate));
        System.out.println(localDate);
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getPeselNumber() {
        return peselNumber;
    }

    public String getAddress() {
        return address;
    }
}


