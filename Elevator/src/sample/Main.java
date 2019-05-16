package sample;

import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.shape.Rectangle;
import javafx.scene.paint.Color;
import javafx.util.Duration;


import java.awt.*;

import static java.lang.Math.abs;

public class Main extends Application {

    static Rectangle rect = new Rectangle();
    static Rectangle rect1 = new Rectangle();
    static Rectangle rect2 = new Rectangle();
    static Circle c1=new Circle();
    static Circle c2=new Circle();
    static Circle c3=new Circle();
    static Circle c4=new Circle();
    static Circle c5=new Circle();
    static Circle c6=new Circle();
    static Circle c7=new Circle();
    static Circle c8=new Circle();
    static Circle c9=new Circle();
    @Override
    public void start(Stage primaryStage) throws Exception{


        //public void start(Stage stage) {
        /*
        Label nameLbl = new Label("Enter your name:");
        TextField nameFld = new TextField();
        Label msg = new Label();
        // задается css для надписи
        msg.setStyle("-fx-text-fill: blue;");
        Button sayHelloBtn = new Button("Say Hello");
        Button exitBtn = new Button("Exit");
        sayHelloBtn.setOnAction(e -> {
            String name = nameFld.getText();
            if (name.trim().length() > 0) {
                msg.setText("Hello " + name);
            } else {
                msg.setText("Hello there");
            }
        });
        exitBtn.setOnAction(e -> Platform.exit());


        VBox root = new VBox();
        root.setSpacing(5);
        root.getChildren().addAll(nameLbl, nameFld,
                msg, sayHelloBtn, exitBtn);
        Scene scene = new Scene(root, 350, 150);
        stage.setScene(scene);
        stage.setTitle("Improved Hello JavaFX Application");
        stage.show();
*/

        Group root = new Group();
       // Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        root.getChildren().add(FXMLLoader.load(getClass().getResource("sample.fxml")));

        c1.setCenterX(39);
        c1.setCenterY(867);
        c1.setRadius(8);
        c1.setFill(Color.BLACK);

        c2.setCenterX(39);
        c2.setCenterY(767);
        c2.setRadius(8);
        c2.setFill(Color.BLACK);

        c3.setCenterX(39);
        c3.setCenterY(667);
        c3.setRadius(8);
        c3.setFill(Color.BLACK);

        c4.setCenterX(39);
        c4.setCenterY(567);
        c4.setRadius(8);
        c4.setFill(Color.BLACK);

        c5.setCenterX(39);
        c5.setCenterY(467);
        c5.setRadius(8);
        c5.setFill(Color.BLACK);

        c6.setCenterX(39);
        c6.setCenterY(367);
        c6.setRadius(8);
        c6.setFill(Color.BLACK);

        c7.setCenterX(39);
        c7.setCenterY(267);
        c7.setRadius(8);
        c7.setFill(Color.BLACK);

        c8.setCenterX(39);
        c8.setCenterY(167);
        c8.setRadius(8);
        c8.setFill(Color.BLACK);

        c9.setCenterX(39);
        c9.setCenterY(67);
        c9.setRadius(8);
        c9.setFill(Color.BLACK);

        //Первый лифт
        rect.setX(135);
        rect.setY(808);
        //rect.setY(Building.queue.get(0).curFloor);
        rect.setWidth(106);
        rect.setHeight(82);
        rect.setFill(Color.BROWN);

        //Второй лифт
        rect1.setX(370);
        rect1.setY(808);
        rect1.setWidth(106);
        rect1.setHeight(82);
        rect1.setFill(Color.BROWN);

        //Третий лифт
        rect2.setX(615);
        rect2.setY(808);
        rect2.setWidth(106);
        rect2.setHeight(82);
        rect2.setFill(Color.BROWN);

        root.getChildren().add(rect);
        root.getChildren().add(rect1);
        root.getChildren().add(rect2);
        root.getChildren().add(c1);
        root.getChildren().add(c2);
        root.getChildren().add(c3);
        root.getChildren().add(c4);
        root.getChildren().add(c5);
        root.getChildren().add(c6);
        root.getChildren().add(c7);
        root.getChildren().add(c8);
        root.getChildren().add(c9);

        //KeyFrame end=new KeyFrame(Duration.millis(2000),new KeyValue(rect.yProperty(),rect.getY()-(abs(Building.queue.get(0).desiredFloor-Building.queue.get(0).curFloor)*100)));

        KeyValue xVal=new KeyValue(rect.yProperty(),rect.getY());
        KeyFrame end1=new KeyFrame(Duration.millis(2000),xVal);

        KeyValue xVal1=new KeyValue(rect1.yProperty(),rect1.getY());
        KeyFrame end11=new KeyFrame(Duration.millis(2000),xVal1);

        KeyValue xVal2=new KeyValue(rect2.yProperty(),rect2.getY());
        KeyFrame end12=new KeyFrame(Duration.millis(2000),xVal2);

        Timeline timeline = new Timeline();
        timeline.getKeyFrames().addAll(end1);
        timeline.getKeyFrames().addAll(end11);
        timeline.getKeyFrames().addAll(end12);
        //Scene scene1 = new Scene(root1, 200, 150);
        //primaryStage.setScene(scene1);


        //timeline.setCycleCount(Timeline.INDEFINITE);
        //timeline.setAutoReverse(true);
        //timeline.getKeyFrames().addAll(end);
        timeline.play();

        primaryStage.setTitle("Elevator!");
        primaryStage.setScene(new Scene(root, 800, 900));



        primaryStage.show();
    }

    public static void main(String[] args) {

        Building building = new Building();

        building.Work();

        launch(args);
    }
}
