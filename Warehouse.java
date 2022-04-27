package Seaport;

import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Warehouse extends Thread {
    public Queue<Containers> containers = new LinkedList<Containers>();
    private int time;
    public Map<Number, String> arrivalList = new HashMap<>();
    private int maxNumOfContainers;

    public Warehouse(int maxNumOfContainers) {

    }

    public void unloadContainer(Containers c) throws IOException {
        if (maxNumOfContainers != 0) {
            maxNumOfContainers--;
            int type = c.getType();
            String typeString = String.valueOf(type);
            containers.add(c);
            LocalDate localdate = LocalDate.now();
            setTimeOfArrivals(c.getId(), localdate);
        }
    }

    public void setTimeOfArrivals(int id, LocalDate localdate) throws IOException {
        arrivalList.put(id, localdate.toString());
        FileWriter writer = new FileWriter("Seaport/ArrivalTimesToWarehouse.txt", true);
        writer.write(id + " " + String.valueOf(localdate) + "\n");
    }

    public void getTimeOfArrivals() {
        arrivalList.values().stream()
                .forEach(System.out::println);
    }

    public void deletionMechanism() {

    }
}
