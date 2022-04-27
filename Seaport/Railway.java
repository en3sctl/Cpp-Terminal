package Seaport;

import java.util.LinkedList;
import java.util.Queue;

public class Railway extends Thread {
    public Queue<Containers> containers = new LinkedList<Containers>();

    public Railway() {

    }
    public void unload(Containers c) throws InterruptedException {
        if (containers.size() == 10) {
            for (int i = 0; i < 10; i++) {
                containers.remove();
            }
            Thread.sleep(30000);
            containers.add(c);
        } else {
            containers.add(c);
        }
    }
}
