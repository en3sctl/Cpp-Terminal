package Seaport;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException{
        // create a seaport with at least five different types of container ships loaded with different containers.
        // Additionally, several containers of different types should be placed in the warehouse.

        // After starting the application, the user should be able to call all the functionalities via the command
        // console and the implemented menu.

        //Type of Containers:
        // Net weight of a standard container: 1000 kg
        // Net weight of a heavy container: 10000 kg
        //1 - Standard Container
        //2 - Heavy Container (A type of standard container)
        //3 - Refrigerated Container (A type of heavy container, requiring connection to the ship’s electrical network)
        //4 - A container for liquids cargo (A type of standard container)
        //5 - A container for explosives cargo (A type of standard container)
        //6 - A container for toxic powdery cargo (A type of heavy container)
        //7 - A container for toxic liquid cargo (That is not only a kind of heavy container, but also has the features of a container for liquids cargo)

        Sender s = new Sender("Enes", "Catal", "99012600000", "Turkey/Istanbul");
        Containers c1 = new Containers(s, 1000, true, true, 1);
        Containers c2 = new Containers(s, 2000, true, false, 2);
        Containers c3 = new Containers(s, 1500, true, true, 3);
        Containers c4 = new Containers(s, 2000, true, true, 4);
        Containers c5 = new Containers(s, 1000, true, true, 5);
        Containers c6 = new Containers(s, 1500, true, true, 6);
        Containers c7 = new Containers(s, 2000, true, true, 7);

        Queue<Ship> shipQueue = new LinkedList<Ship>();
        Warehouse w = new Warehouse(20);
        Railway r = new Railway();
        Ship sh1 = new Ship("A", "China", "Poland", "railway", 2, 4, 0, 10, 250000, w, r);
        Ship sh2 = new Ship("B", "US", "Poland", "railway", 5, 7, 1, 12, 50000, w, r);
        Ship sh3 = new Ship("C", "Italy", "Poland", "railway", 7, 9, 1, 20, 100000, w, r);
        Ship sh4 = new Ship("D", "Australia", "Poland", "railway", 4, 6, 1, 15, 18000, w, r);
        Ship sh5 = new Ship("E", "Belgium", "Poland", "railway", 3, 5, 2, 20, 12000, w, r);
        shipQueue.add(sh1);
        shipQueue.add(sh2);
        shipQueue.add(sh3);
        shipQueue.add(sh4);
        shipQueue.add(sh5);

        while (true) {
            System.out.println("Menu:");
            System.out.println("Please Press 1-5 to select a ship");
            System.out.println("Please press 0 to exit from the loop");
            Scanner scn = new Scanner(System.in);
            int select = scn.nextInt();
            if (select == 0) {
                break;
            }
            switch (select) {
                case 1:
                    System.out.println("Please write add for a adding a container to the ship");
                    System.out.println("Please write unload for unloading a container from the ship");
                    scn.nextLine();
                    String operation = scn.nextLine();
                    if (operation.equals("add")) {
                        System.out.println("Please indicate the type of container you'd like to add (1-7)");
                        int contNum = scn.nextInt();
                        switch (contNum) {
                            case 1:
                                sh1.loadContainer(c1);
                                break;
                            case 2:
                                sh1.loadContainer(c2);
                                break;
                            case 3:
                                sh1.loadContainer(c1);
                                break;
                            case 4:
                                sh1.loadContainer(c2);
                                break;
                            case 5:
                                sh1.loadContainer(c1);
                                break;
                            case 6:
                                sh1.loadContainer(c2);
                                break;
                            case 7:
                                sh1.loadContainer(c1);
                                break;
                        }
                    } else if (operation.equals("unload")) {
                        sh1.unload();
                    }
                    break;
                case 2:
                    System.out.println("Please write add for a adding a container to the ship");
                    System.out.println("Please write unload for unloading a container from the ship");
                    scn.nextLine();
                    operation = scn.nextLine();
                    if (operation.equals("add")) {
                        System.out.println("Please indicate the type of container you'd like to add (1-7)");
                        int contNum = scn.nextInt();
                        switch (contNum) {
                            case 1:
                                sh2.loadContainer(c1);
                                break;
                            case 2:
                                sh2.loadContainer(c2);
                                break;
                            case 3:
                                sh2.loadContainer(c1);
                                break;
                            case 4:
                                sh2.loadContainer(c2);
                                break;
                            case 5:
                                sh2.loadContainer(c1);
                                break;
                            case 6:
                                sh2.loadContainer(c2);
                                break;
                            case 7:
                                sh2.loadContainer(c1);
                                break;
                        }
                    } else if (operation.equals("unload")) {
                        sh2.unload();
                    }
                    break;
                case 3:
                    System.out.println("Please write add for a adding a container to the ship");
                    System.out.println("Please write unload for unloading a container from the ship");
                    scn.nextLine();
                    operation = scn.nextLine();
                    if (operation.equals("add")) {
                        System.out.println("Please indicate the type of container you'd like to add (1-7)");
                        int contNum = scn.nextInt();
                        switch (contNum) {
                            case 1:
                                sh3.loadContainer(c1);
                                break;
                            case 2:
                                sh3.loadContainer(c2);
                                break;
                            case 3:
                                sh3.loadContainer(c1);
                                break;
                            case 4:
                                sh3.loadContainer(c2);
                                break;
                            case 5:
                                sh3.loadContainer(c1);
                                break;
                            case 6:
                                sh3.loadContainer(c2);
                                break;
                            case 7:
                                sh3.loadContainer(c1);
                                break;
                        }
                    } else if (operation.equals("unload")) {
                        sh3.unload();
                    }
                    break;
                case 4:
                    System.out.println("Please write add for a adding a container to the ship");
                    System.out.println("Please write unload for unloading a container from the ship");
                    scn.nextLine();
                    operation = scn.nextLine();
                    if (operation.equals("add")) {
                        System.out.println("Please indicate the type of container you'd like to add (1-7)");
                        int contNum = scn.nextInt();
                        switch (contNum) {
                            case 1:
                                sh4.loadContainer(c1);
                                break;
                            case 2:
                                sh4.loadContainer(c2);
                                break;
                            case 3:
                                sh4.loadContainer(c1);
                                break;
                            case 4:
                                sh4.loadContainer(c2);
                                break;
                            case 5:
                                sh4.loadContainer(c1);
                                break;
                            case 6:
                                sh4.loadContainer(c2);
                                break;
                            case 7:
                                sh4.loadContainer(c1);
                                break;
                        }
                    } else if (operation.equals("unload")) {
                        sh4.unload();
                    }
                    break;
                case 5:
                    System.out.println("Please write add for a adding a container to the ship");
                    System.out.println("Please write unload for unloading a container from the ship");
                    scn.nextLine();
                    operation = scn.nextLine();
                    if (operation.equals("add")) {
                        System.out.println("Please indicate the type of container you'd like to add (1-7)");
                        int contNum = scn.nextInt();
                        switch (contNum) {
                            case 1:
                                sh5.loadContainer(c1);
                                break;
                            case 2:
                                sh5.loadContainer(c2);
                                break;
                            case 3:
                                sh5.loadContainer(c1);
                                break;
                            case 4:
                                sh5.loadContainer(c2);
                                break;
                            case 5:
                                sh5.loadContainer(c1);
                                break;
                            case 6:
                                sh5.loadContainer(c2);
                                break;
                            case 7:
                                sh5.loadContainer(c1);
                                break;
                        }
                    } else if (operation.equals("unload")) {
                        sh5.unload();
                    }
                    break;
            }
        }
    }
}

