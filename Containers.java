package Seaport;

public class Containers {
    private static int cnt = 1; //counter
    private int type; //type of container
    private int id = 0;
    private Sender sender;
    private int tare;
    private boolean secInfo; //security info
    private int netWeight;
    private int grossWeight;
    private boolean certificateInfo;

    //tare => The weight of the empty container
    public Containers(Sender sender, int tare, boolean secInfo, boolean certificateInfo, int type) {
        this.sender = sender;
        this.tare = tare;
        this.secInfo = secInfo;
        this.type = type;
        setNetWeight(type);
        setGrossWeight(tare);
        this.certificateInfo = certificateInfo;
        id = cnt++;
    }

    public int getId() {
        return id;
    }

    public int getType() {
        return type;
    }

    public int getNetWeight() {
        return netWeight;
    }

    public int getGrossWeight() {
        return grossWeight;
    }

    public boolean getSecInfo() {
        return secInfo;
    }

    public boolean getCertificateInfo() {
        return certificateInfo;
    }

    public void setNetWeight(int type) {
        netWeight = (type == 1 || type == 4 || type == 5) ? 1000 : 10000;
    }

    public void setGrossWeight(int tare) {
        grossWeight = netWeight + tare;
    }
}
