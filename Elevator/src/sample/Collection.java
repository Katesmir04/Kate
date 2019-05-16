package sample;

public class Collection {
    int curFloor;
    int desiredFloor;
    int weight;

    Collection (int curFloor, int desiredFloor, int weight)
    {
        this.curFloor = curFloor;
        this.desiredFloor = desiredFloor;
        this.weight = weight;

    }

    public int getCurrentFloor() {
        return curFloor;
    }

    public int getDesiredFloor() {
        return desiredFloor;
    }




}
