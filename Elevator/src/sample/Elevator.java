package sample;

public class Elevator {
    public int getCurFloor() {
        return curFloor;
    }

    public int getStatus() {
        return status;
    }

    public void setCurFloor(int curFloor) {
        this.curFloor = curFloor;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    public int curFloor;
    public  int destFloor;
    public int status;

    Elevator(int curFloor)
    {
        this.curFloor = curFloor;
        status = 0;
    }
}