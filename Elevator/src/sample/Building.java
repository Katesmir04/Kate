package sample;

import java.util.ArrayList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;

public class Building {

    public static ArrayList <Collection> queue = new ArrayList();
    public static ArrayList <Elevator> elevNumber = new ArrayList<>();
    public static int floorNumber;

    public static int getElevatorsNumber() {
        return elevatorsNumber;
    }

    public static int elevatorsNumber;

    Building()
    {
        floorNumber = 9;
        elevatorsNumber =3;
        Random rand = new Random();
        for (int i=0; i< elevatorsNumber; i++)
        {
            int floor1 = rand.nextInt(floorNumber)+1;
            Elevator elev = new Elevator(floor1);
            elevNumber.add(elev);
        }
    }

    static synchronized void Add(Collection call)
    {
        Building.queue.add(call);
    }

    void Work()
    {
        ThreadGenerator thread1 = new ThreadGenerator();
        ThreadLiftManagment thread2 = new ThreadLiftManagment();

        thread1.start();
        thread2.start();

        //System.out.println(queue.poll().weight);
    }

}