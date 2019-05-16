package sample;

import java.util.Random;
import java.util.concurrent.Semaphore;

public class ThreadGenerator extends Thread
{
    int i =1;
    public Semaphore sem = new Semaphore(1);

    public synchronized void Add(int floor1, int floor2, int weight)
    {
        Collection call = new Collection(floor1, floor2, weight);
        Building.queue.add(call);

    }


    public void run ()
    {
        while(1==1) {
            try {
                sem.acquire();
                System.out.println("Сгенерировалась заявка: ");
            } catch (InterruptedException ex) {
                System.out.println("Ошибка.");
            }
            sem.release();


            Random rand = new Random();

            int floor1 = rand.nextInt(Building.floorNumber) + 1;
            int floor2 = rand.nextInt(Building.floorNumber) + 1;
            int weight = rand.nextInt(76) + 1;

            Add(floor1, floor2, weight);

            try{
                sleep(4500);

            }
            catch(InterruptedException ex)
            {
                System.out.println("Ошибка.");
            }

            try {
                sem.acquire();
                for (int i = 0; i<Building.queue.size();i++)
                {
                    System.out.println("Тек этаж:"+Building.queue.get(i).curFloor +
                            "  "+"Едет на :"+Building.queue.get(i).desiredFloor + "  "+"Вес: "+Building.queue.get(i).weight);
                }
                sem.release();
            } catch (InterruptedException ex) {
                System.out.println("Ошибка.");
            }




        }

    }
}