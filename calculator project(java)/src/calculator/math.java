/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

/**
 *
 * @author AHmed
 */
public class math extends Calc{
   
    double res;
   
   public void start() {
       
       Button btn0 = new Button();
        btn0.setText("sin(");
        btn0.setMinSize(100, 40);
        Button btn = new Button();
        btn.setText("cos(");
        btn.setMinSize(50, 40);
        Button btn2 = new Button();
        btn2.setText("cosh(");
        btn2.setMinSize(50, 40);
         Button btn3 = new Button();
        btn3.setText("sinh");
        btn3.setMinSize(50, 40);
         Button btn4 = new Button();
        btn4.setText("tan(");
        btn4.setMinSize(50, 40);
        Button btn5 = new Button();
        btn5.setText("tanh(");
        btn5.setMinSize(50, 40);
        Button btn6 = new Button();
        btn6.setText("exp(");
        btn6.setMinSize(50, 40);
        Button btn7 = new Button();
        btn7.setText("pow(");
        btn7.setMinSize(50, 40);
        Button btn8 = new Button();
        btn8.setText("sqrt(");
        btn8.setMinSize(50, 40);
        Button btn9 = new Button();
        btn9.setText("exp(");
        btn9.setMinSize(50, 40);
        Button btn155 = new Button();
        btn155.setText("degr(");
        btn155.setMinSize(50, 40);
        TextField r=new TextField();
        r.setText("");
        Button btn11 = new Button();
        btn11.setText("=");
        btn11.setMinSize(50, 40);
        Button btn12 = new Button();
        btn12.setText("-");
        btn12.setMinSize(50, 40);
        Button btn13 = new Button();
        btn13.setText("  * ");
        btn13.setMinSize(50, 40);
        Button btn14 = new Button();
        btn14.setText("/ ");
        btn14.setMinSize(50, 40);
        Button btn15 = new Button();
        btn15.setText(".");
        btn15.setMinSize(50, 40);
        Button btn16 = new Button();
        btn16.setText("(");
        btn16.setMinSize(50, 40);
       Button btn17 = new Button();
        btn17.setText(")");
        Button btn18 = new Button();
        btn18.setText("CE");
        btn18.setMinSize(50, 40);
        btn17.setMinSize(50, 40);
        GridPane x=new GridPane ();
        
        HBox root = new HBox();
        HBox two = new HBox();
        HBox three = new HBox();
        HBox thr = new HBox();
        root.getChildren().addAll(btn0,btn12,btn13,btn15);
        two.getChildren().addAll(btn,btn2,btn3,btn11,btn16);
        three.getChildren().addAll(btn4,btn5,btn6,btn155,btn17);
        thr.getChildren().addAll(btn7,btn8,btn9,btn14,btn18);
         btn.setOnAction(e-> {
            
                 w=r.getText();
            r.setText(w+"cos(");});
        btn0.setOnAction(e-> {
     
                 w=r.getText();
            r.setText(w+"sine(");});
        btn2.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) {
                 w=r.getText();
            r.setText(w+"cosh(");
        }});
         btn3.setOnAction(e->{
             w=r.getText();
            r.setText(w+"sinh(");});
          btn4.setOnAction(e->{
              w=r.getText();
            r.setText(w+"tan(");});
          btn5.setOnAction(e->{
             w=r.getText();
            r.setText(w+"tanh(");});
          btn6.setOnAction(e->{
             w=r.getText();
            r.setText(w+"exp(");});
          btn7.setOnAction(e->{
             w=r.getText();
            r.setText(w+"pow(");});
          btn8.setOnAction(e->{
             w=r.getText();
            r.setText(w+"sqrt(");});
          btn9.setOnAction(e->{
             w=r.getText();
            r.setText(w+"e");});
          btn155.setOnAction(e->{
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
            r.setText(w+"(");});
          btn17.setOnAction(e->{
             w=r.getText();
            r.setText(w+")");});
          btn11.setOnAction(e->{
             w=r.getText();
           res=wer.wer(w);
          r.setText("res");});
          btn18.setOnAction(e->{
            int zs;
            zs=w.length();
        r.setText(w.substring(0, zs)); }); 
     
      x.setHgap(5);
      x.setVgap(.5);
      x.add(root, 0, 10);
      x.add(two, 0, 9);
      x.add(three, 0, 8);
   x.add(r, 0, 0);
   x.add(thr, 0, 7);
       
         
        

      //  Scene scene1 = new Scene(x);
    
        
       // Stage.setTitle("Hello World!");
        //Stage.setScene(scene1);
       // Stage.show();
    
}
    
 public static void main(String[] args) {
        launch(args);
        
    }}

    