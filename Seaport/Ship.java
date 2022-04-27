package Seaport;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class Ship {
    private Railway railway;
    private Warehouse warehouse;
    public Queue<Containers> containerQueue = new LinkedList<Containers>();

    private static int cnt = 1;
    private int id = 0;
    private String name;
    private String homePort;
    private String transportOrigin;
    private String destination;
    private int maxNumToxOrExp;
    private int maxNumHeavy;
    private int maxNumReqElectCon;
    private int maxNumAll;
    private int maxWeightLoad;

    public Ship(String name, String homePort, String transportOrigin, String destination,
                int maxNumToxOrExp, int maxNumHeavy, int maxNumReqElectCon, int maxNumAll, int maxWeightLoad,
                Warehouse warehouse, Railway railway) {
        this.name = name;
        this.homePort = homePort;
        this.transportOrigin = transportOrigin;
        this.destination = destination;
        this.maxNumAll = maxNumAll;
        this.maxNumHeavy = maxNumHeavy;
        this.maxNumReqElectCon = maxNumReqElectCon;
        this.maxWeightLoad = maxWeightLoad;
        this.maxNumToxOrExp = maxNumToxOrExp;
        this.warehouse = warehouse;
        this.railway = railway;
        id = cnt++;
    }

    public int getId() {
        return id;
    }

    public int getNumberOfLoadedContainer() {
        return containerQueue.size();
    }

    public String getName() {
        return name;
    }

    public String getHomePort() {
        return homePort;
    }

    public String getTransportOrigin() {
        return transportOrigin;
    }

    public String getDestination() {
        return destination;
    }

    public void loadContainer(Containers c) {
        int t = c.getType();
        if (c.getSecInfo()) {
            if (c.getCertificateInfo()) {
                if (maxWeightLoad > 0) {
                    if ((maxWeightLoad - c.getGrossWeight() > 0) && maxNumAll > 0) {
                        switch (t) {
                            case 1:
                                containerQueue.add(c);
                                maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                maxNumAll--;
                                System.out.println("A standard container has been added.");
                                break;
                            case 2:
                                if (maxNumHeavy > 0) {
                                    maxNumHeavy--;
                                    maxNumAll--;
                                    containerQueue.add(c);
                                    maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                    System.out.println("A heavy container has been added.");
                                    break;
                                } else {
                                    System.out.println("Cannot load, there is no place for another heavy container.");
                                    break;
                                }
                            case 3:
                                if (maxNumReqElectCon > 0 && maxNumHeavy > 0) {
                                    containerQueue.add(c);
                                    maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                    maxNumAll--;
                                    maxNumHeavy--;
                                    maxNumReqElectCon--;
                                    System.out.println("A refrigerated container has been added.");
                                    break;
                                } else {
                                    System.out.println("Cannot load, there is no place for another refrigerated container.");
                                    break;
                                }
                            case 4:
                                containerQueue.add(c);
                                maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                maxNumAll--;
                                System.out.println("A container for liguids cargo has been added.");
                                break;
                            case 5:
                                if (maxNumToxOrExp > 0) {
                                    containerQueue.add(c);
                                    maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                    maxNumAll--;
                                    maxNumToxOrExp--;
                                    System.out.println("A container for explosives cargo has been added.");
                                    break;
                                } else {
                                    System.out.println("Cannot load, there is no place for another toxic or explosive container.");
                                    break;
                                }
                            case 6:
                                if (maxNumToxOrExp > 0) {
                                    if (maxNumHeavy > 0) {
                                        containerQueue.add(c);
                                        maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                        maxNumAll--;
                                        maxNumToxOrExp--;
                                        System.out.println("A container for toxic powdery cargo has been added.");
                                        break;
                                    } else {
                                        System.out.println("Cannot load another heavy container.");
                                        break;
                                    }
                                } else {
                                    System.out.println("Cannot load, there is no place for another toxic or explosive container.");
                                    break;
                                }
                            case 7:
                                if (maxNumToxOrExp > 0) {
                                    if (maxNumHeavy > 0) {
                                        containerQueue.add(c);
                                        maxWeightLoad = maxWeightLoad - c.getGrossWeight();
                                        maxNumAll--;
                                        maxNumToxOrExp--;
                                        System.out.println("A container for toxic liquid cargo has been added.");
                                        break;
                                    } else {
                                        System.out.println("Cannot load another heavy container.");
                                        break;
                                    }
                                } else {
                                    System.out.println("Cannot load, there is no place for another toxic or explosive container.");
                                    break;
                                }
                        }
                    } else {
                        System.out.println("Cannot load because the top limit of ship weight or maximum number of all containers will be exceeded if it is loaded.");
                    }
                } else {
                    System.out.println("Cannot load because the top limit of ship weight exceeded.");
                }
            } else {
                System.out.println("Cannot load because the certificate info is not provided.");
            }
        } else {
            System.out.println("Cannot load because security info is not provided.");
        }

    }

    public void unload() throws InterruptedException, IOException {
        Containers cont = containerQueue.peek();
        int typeRemovedContainer = cont.getType();
        switch (typeRemovedContainer) {
            case 1:
            case 4:
                maxWeightLoad = maxWeightLoad + cont.getGrossWeight();
                maxNumAll++;
                break;
            case 2:
                maxWeightLoad = maxWeightLoad + cont.getGrossWeight();
                maxNumAll++;
                maxNumHeavy++;
                break;
            case 3:
                maxWeightLoad = maxWeightLoad + cont.getGrossWeight();
                maxNumAll++;
                maxNumHeavy++;
                maxNumReqElectCon++;
                break;
            case 5:
                maxWeightLoad = maxWeightLoad + cont.getGrossWeight();
                maxNumAll++;
                maxNumToxOrExp++;
                break;
            case 6:
            case 7:
                maxWeightLoad = maxWeightLoad + cont.getGrossWeight();
                maxNumAll++;
                maxNumToxOrExp++;
                maxNumHeavy++;
                break;
        }
        if (destination.equals("warehouse")) {
            warehouse.unloadContainer(cont);
        } else {
            railway.unload(cont);
        }
        containerQueue.remove();
        System.out.println("A container has been removed.");

    }
}