/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;



public class Calc extends Application {
    String w=" ";
    String k=" ";
    String fgt;
    int f=0;
       double as;
 
    NewClass wer=new NewClass();
    @Override
    public void start(Stage primaryStage) {
        
        Button btn0 = new Button();
        btn0.setText("0");
        btn0.setMinSize(80, 40);
        Button btn1 = new Button();
        btn1.setText("1");
        btn1.setMinSize(40, 40);
        Button btn2 = new Button();
        btn2.setText("2");
        btn2.setMinSize(40, 40);
         Button btn3 = new Button();
        btn3.setText("3");
        btn3.setMinSize(40, 40);
         Button btn4 = new Button();
        btn4.setText("4");
        btn4.setMinSize(40, 40);
        Button btn5 = new Button();
        btn5.setText("5");
        btn5.setMinSize(40, 40);
        Button btn6 = new Button();
        btn6.setText("6");
        btn6.setMinSize(40, 40);
        Button btn7 = new Button();
        btn7.setText("7");
        btn7.setMinSize(40, 40);
        Button btn8 = new Button();
        btn8.setText("8");
        btn8.setMinSize(40, 40);
        Button btn9 = new Button();
        btn9.setText("9");
        btn9.setMinSize(40, 40);
        Button btn10 = new Button();
        btn10.setText("+");
        btn10.setMinSize(40, 40);
        Button btn11 = new Button();
        btn11.setText("=");
        btn11.setMinSize(40, 40);
        Button btn12 = new Button();
        btn12.setText("-");
        btn12.setMinSize(40, 40);
        Button btn13 = new Button();
        btn13.setText("*");
        btn13.setMinSize(40, 40);
        Button btn14 = new Button();
        btn14.setText("/");
        btn14.setMinSize(40, 40);
        Button btn15 = new Button();
        btn15.setText(".");
        btn15.setMinSize(40, 40);
        Button btn16 = new Button();
        btn16.setText(")");
        btn16.setMinSize(40, 40);
        Button btn17 = new Button();
        btn17.setText("clear");
        Button btn18 = new Button();
        btn18.setText("CE");
        btn18.setMinSize(40, 40);
        btn17.setMinSize(40, 40);
        TextField r=new TextField();
        r.setEditable(false);
        r.setText("");
        btn1.setOnAction(e-> {
            
                 w=r.getText();
            r.setText(w+"1");});
        btn0.setOnAction( e-> {
     
                 w=r.getText();
            r.setText(w+"0");});
        btn2.setOnAction(e-> {
                 w=r.getText();
            r.setText(w+"2");
        });
         btn3.setOnAction(e->{
             w=r.getText();
            r.setText(w+"3");});
          btn4.setOnAction(e->{
              w=r.getText();
            r.setText(w+"4");});
          btn5.setOnAction(e->{
             w=r.getText();
            r.setText(w+"5");});
          btn6.setOnAction(e->{
             w=r.getText();
            r.setText(w+"6");});
          btn7.setOnAction(e->{
             w=r.getText();
            r.setText(w+"7");});
          btn8.setOnAction(e->{
             w=r.getText();
            r.setText(w+"8");});
          btn9.setOnAction(e->{
             w=r.getText();
            r.setText(w+"9");});
          btn10.setOnAction(e->{
             w=r.getText();
            r.setText(w+"+");
           });
          btn12.setOnAction(e->{
             w=r.getText();
            r.setText(w+"-");
          
           });
          btn13.setOnAction(e->{
             w=r.getText();
            r.setText(w+"*");
      
           });
          btn14.setOnAction(e->{
             w=r.getText();
            r.setText(w+"/");});
          btn15.setOnAction(e->{
             w=r.getText();
            r.setText(w+".");});
          btn16.setOnAction(e->{
               w=r.getText();
            r.setText(w+")");
           });
          btn17.setOnAction(e->{
             w=r.getText();
            r.setText("");});
          btn18.setOnAction(e->{
            int zs;
            w=r.getText();
            zs=w.length();
            if(zs!=0)
      r.setText(w.substring(0,zs-1));
        
            });
          btn11.setOnAction(e->{
             w=r.getText();
            r.setText(w+"=");
           as= wer.equal(w);
        k= String .valueOf(as);
        r.setText(k);});
          Button btn02 = new Button();
        btn02.setText("sin(");
        btn02.setMinSize(100, 40);
        Button btn123 = new Button();
        btn123.setText("cos(");
        btn123.setMinSize(50, 40);
        Button btn22 = new Button();
        btn22.setText("cosh(");
        btn22.setMinSize(50, 40);
         Button btn32 = new Button();
        btn32.setText("sinh");
        btn32.setMinSize(50, 40);
         Button btn42 = new Button();
        btn42.setText("tan(");
        btn42.setMinSize(50, 40);
        Button btn52 = new Button();
        btn52.setText("tanh(");
        btn52.setMinSize(50, 40);
        Button btn62 = new Button();
        btn62.setText("exp(");
        btn62.setMinSize(50, 40);
        Button btn72 = new Button();
        btn72.setText("log(");
        btn72.setMinSize(50, 40);
        Button btn82 = new Button();
        btn82.setText("sqrt(");
        btn82.setMinSize(50, 40);
        Button btn92 = new Button();
        btn92.setText("ln(");
        btn92.setMinSize(50, 40);
        Button btn102 = new Button();
        btn102.setText("degr(");
        btn102.setMinSize(50, 40);
      
        Button btn182 = new Button();
        btn182.setText("CE");
        btn182.setMinSize(50, 40);
        GridPane x=new GridPane ();
        
        HBox root = new HBox();
        HBox two = new HBox();
        HBox three = new HBox();
        HBox thr = new HBox();
        root.getChildren().addAll(btn0,btn12,btn13,btn15,btn02,btn123);
        two.getChildren().addAll(btn1,btn2,btn3,btn11,btn16,btn22,btn32,btn102);
        three.getChildren().addAll(btn4,btn5,btn6,btn10,btn17,btn42,btn52,btn62);
        thr.getChildren().addAll(btn7,btn8,btn9,btn14,btn18,btn72,btn82,btn92);
      x.setHgap(5);
      x.setVgap(.5);
      x.add(root, 0, 10);
      x.add(two, 0, 9);
      x.add(three, 0, 8);
      x.add(r, 0, 0);
   x.add(thr, 0, 7);
       
        Scene scene = new Scene(x);
            
         btn123.setOnAction(e-> {
            
                 w=r.getText();
            r.setText(w+"cos(");});
        btn02.setOnAction(e-> {
     
                 w=r.getText();
            r.setText(w+"sin(");});
        btn22.setOnAction(e->{
           
                 w=r.getText();
            r.setText(w+"cosh(");
        });
         btn32.setOnAction(e->{
             w=r.getText();
            r.setText(w+"sinh(");});
          btn42.setOnAction(e->{
              w=r.getText();
            r.setText(w+"tan(");});
          btn52.setOnAction(e->{
             w=r.getText();
            r.setText(w+"tanh(");});
          btn62.setOnAction(e->{
             w=r.getText();
            r.setText(w+"exp(");});
          btn72.setOnAction(e->{
             w=r.getText();
            r.setText(w+"log(");});
          btn82.setOnAction(e->{
             w=r.getText();
            r.setText(w+"sqrt(");});
          btn92.setOnAction(e->{
             w=r.getText();
            r.setText(w+"ln(");});
          btn102.setOnAction(e->{
             w=r.getText();
            r.setText(w+"degr(");
           });
        
          
        primaryStage .setResizable(false);
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
         
    }

    public static void main(String[] args) {
        launch(args);
    }
    
}




