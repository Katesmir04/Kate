package sample;

import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.scene.paint.Color;
import javafx.util.Duration;

import static java.lang.Math.abs;

public class ThreadLiftManagment extends Thread {
    private int sleepN=7000;
    private int min = 21;
    private int capacity=56;

    public synchronized void RemoveQueue()
    {
        Building.queue.remove(0);
    }



    public synchronized void Go(int destFloor, int i)
    {
        Building.elevNumber.get(i).setCurFloor(destFloor);

        if (i==0) {
            if (destFloor == 1) {
                Main.rect.setX(135);
                //Main.rect.setY(808);
                Main.rect.setFill(Color.YELLOW);

                //KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), Main.rect.getY() - (abs(Building.queue.get(0).desiredFloor - Building.queue.get(0).curFloor) * 100));
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 808);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 2)
            {
                Main.rect.setX(135);
                //Main.rect.setY(708);
                Main.rect.setFill(Color.YELLOW);
                //KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), Main.rect.getY() - (abs(Building.queue.get(0).desiredFloor - Building.queue.get(0).curFloor) * 100));
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 708);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();

            }
            else if (destFloor == 3)
            {
                Main.rect.setX(135);
                //Main.rect.setY(608);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 608);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 4)
            {
                Main.rect.setX(135);
                //Main.rect.setY(508);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 508);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 5)
            {
                Main.rect.setX(135);
                //Main.rect.setY(408);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 408);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 6)
            {
                Main.rect.setX(135);
                //Main.rect.setY(308);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 308);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 7)
            {
                Main.rect.setX(135);
                //Main.rect.setY(208);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 208);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 8)
            {
                Main.rect.setX(135);
                //Main.rect.setY(108);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 108);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 9)
            {
                Main.rect.setX(135);
                //Main.rect.setY(8);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), 8);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
        }
        //Если это второй лифт
        else if (i==1) {
            if (destFloor == 1) {
                Main.rect1.setX(370);
                //Main.rect.setY(808);
                Main.rect1.setFill(Color.YELLOW);

                //KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), Main.rect.getY() - (abs(Building.queue.get(0).desiredFloor - Building.queue.get(0).curFloor) * 100));
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 808);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 2)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(708);
                Main.rect1.setFill(Color.YELLOW);
                //KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), Main.rect.getY() - (abs(Building.queue.get(0).desiredFloor - Building.queue.get(0).curFloor) * 100));
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 708);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();

            }
            else if (destFloor == 3)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(608);
                Main.rect1.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 608);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 4)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(508);
                Main.rect1.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 508);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 5)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(408);
                Main.rect1.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 408);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 6)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(308);
                Main.rect1.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 308);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 7)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(208);
                Main.rect1.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 208);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 8)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(108);
                Main.rect.setFill(Color.YELLOW);
                //Main.rect1.setFill(Color.BLUE);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 108);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 9)
            {
                Main.rect1.setX(370);
                //Main.rect.setY(8);
                //Main.rect1.setFill(Color.BLUE);
                Main.rect.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect1.yProperty(), 8);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
        }
        //Если это второй лифт
        else if (i==2) {
            if (destFloor == 1) {
                Main.rect2.setX(615);
                //Main.rect.setY(808);
                Main.rect2.setFill(Color.YELLOW);

                //KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), Main.rect.getY() - (abs(Building.queue.get(0).desiredFloor - Building.queue.get(0).curFloor) * 100));
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 808);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 2)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(708);
                Main.rect2.setFill(Color.YELLOW);
                //KeyValue xVal1 = new KeyValue(Main.rect.yProperty(), Main.rect.getY() - (abs(Building.queue.get(0).desiredFloor - Building.queue.get(0).curFloor) * 100));
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 708);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();

            }
            else if (destFloor == 3)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(608);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 608);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 4)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(508);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 508);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 5)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(408);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 408);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 6)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(308);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 308);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 7)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(208);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 208);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 8)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(108);
                //Main.rect.setFill(Color.YELLOW);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 108);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
            }
            else if (destFloor == 9)
            {
                Main.rect2.setX(615);
                //Main.rect.setY(8);
                Main.rect2.setFill(Color.YELLOW);
                KeyValue xVal1 = new KeyValue(Main.rect2.yProperty(), 8);
                KeyFrame end11 = new KeyFrame(Duration.millis(2000), xVal1);
                Timeline timeline = new Timeline();
                timeline.getKeyFrames().addAll(end11);
                timeline.play();
                //Main.rect2.setFill(Color.BROWN);
            }
        }
    }

    public void run ()
    {
        while(1==1)
        {
            if (!Building.queue.isEmpty())
            {

                for(int i =0; i<Building.elevatorsNumber;i++)
                {
                    if ((Building.elevNumber.get(i).status == 0)&&(Building.queue.size()>=3))
                    {
                        Building.elevNumber.get(i).setStatus(1);

                        //Main.rect.setFill(Color.YELLOW);
                        int curFloor = Building.queue.get(0).curFloor;
                        int destFloor = Building.queue.get(0).desiredFloor;
                        int weight = Building.queue.get(0).weight;


                        this.RemoveQueue();
                        //capacity=0;
                        if ((Building.elevNumber.get(i).getCurFloor()==curFloor)&&((capacity+weight)<=capacity))
                        {
                            
                            Go(destFloor, i);
                            System.out.println("Пассажир едет на: " + (i+1)+" лифте."+" На "+destFloor+" этаж.");
                            //capacity=capacity+weight;
                            // Building.elevNumber.get(i).setStatus(0);
                            //Main.rect2.setFill(Color.BROWN);
                        }
                        else if ((Building.elevNumber.get(i).getCurFloor()!=curFloor)&&(weight<=capacity))
                        {
                            //GoCurFloor(destFloor,i,curFloor);
                            Go(curFloor,i);
                            try {
                                //Main.rect.setFill(new Color(50, 51, 204, 50));
                                //Main.rect.setFill(Color.TRANSPARENT);
                                sleep(3000);
                            }
                            catch (InterruptedException ex)
                            {
                                System.out.println("Ошибка");
                            }
                            System.out.println("Лифт: "+(i+1)+" прибыл на вызванный этаж.");
                            Go(destFloor,i);
                            System.out.println("Пассажир едет на: " + (i+1)+" лифте."+" На "+destFloor+" этаж.");
                            //capacity=capacity+weight;
                            //Building.elevNumber.get(i).setStatus(0);
                            //Main.rect2.setFill(Color.BROWN);
                        }

                        Building.elevNumber.get(i).setStatus(0);
                        //Main.rect.setFill(Color.BLACK);
                    }

                }

                for (int i =0; i<Building.elevNumber.size();i++)
                {
                    //Building.elevNumber.get(i).setStatus(0);
                    //Main.rect.setFill(Color.BROWN);
                    //Main.rect1.setFill(Color.BROWN);
                    //Main.rect2.setFill(Color.BROWN);
                }

                //Main.SetI(10);

            }
            try
            {
                sleep(sleepN);
            }
            catch(InterruptedException ex)
            {
                System.out.println("Ошибка.");
            }
        }
    }
}
