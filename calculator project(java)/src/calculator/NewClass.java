
package calculator;


public class NewClass {
 
  public double equal(String t){
      int rre;
      rre=t.length();
      double[] qw=new double[rre];
      char[]dd=new char[rre];
      char[]vb=new char[rre];
       double[] xr=new double[rre];
      double ty,kk=0;
      String asd,df;
char gh='0';
      int n=0,m=0,ll=0;
      double s;
       for (int i=0;i<t.length();i++){
       gh =t.charAt(i);
System.out.println(gh);
     asd=String.valueOf(gh);
     System.out.println(asd);
if(asd.equals("l")||(asd.equals("s"))||asd.equals("t")||gh==('c')||(asd.equals("e"))||asd.equals("d"))
{ kk=wer(t.substring(i, t.length()));
for ( ll=i; ;ll++){
     if(ll==t.length()){
       System.out.println("you should put )at end");
     break;   }
       gh =t.charAt(ll);
       if(gh==')')
           break;
      
}
i=ll;
asd=String.valueOf(kk);}
    if(asd.equals("+")||(asd.equals("-")&&m!=i)||asd.equals("*")||gh=='/'){
       
            df=t.substring(m,i);
 ty=Double.parseDouble(df);
 xr[n]=ty;
 System.out.println(xr[n]);
 vb[n]=gh;
 System.out.println(vb[n]);
 n++;
 m=i+1;
 }}
      if((gh!=')')&&(ll!=t.length())){
xr[n]=Double.parseDouble(t.substring(m,t.length()));
 System.out.println(xr[n]);}
     else
    xr[n]=kk;
   
       double io=0,tt=100;
                 int j=0,d=0;
     for(int bb=0;bb<=n;bb++){
         if(vb[bb]=='*'||vb[bb]==('/')){
             io=1;
              if(tt==bb-1)
                 --d;
                 if(vb[bb]==('*')){
                     xr[bb+1]=xr[bb]*xr[bb+1];
                 }
                  else
                      try{
                  xr[bb+1]=xr[bb]/xr[bb+1];}
                   catch(ArithmeticException ex){
          System.out.println("Exception: an doubel "+ 
"cannot be divided by zero ");}

                 qw[d]=xr[bb+1];
                 d++;
                 tt=bb;
                 System.out.println(qw[d-1]+"  "+d);
continue; }
dd[j]=vb[bb];
j++;
 System.out.println(dd[j-1]);
if(io==1){
    io=0;
continue;}
    qw[d]=xr[bb];
    d++;
     System.out.println(qw[d-1]+" "+d);
     
    }
      s=qw[0];
   
      
 for(int i=0;i<=n;i++){
    gh=dd[i];
     if(gh=='+')
 s=s+qw[i+1];
      if(gh=='-')
  s=s-qw[i+1];  
   
 }
 return s;
}
public double wer(String y){
 double ty=0,kk=0;
char gh,c;
String asd,df=" ";
String h;

  int n;
  double m=0;
  n=y.length();
       for (int i=0;i<y.length();i++){
       gh =y.charAt(i);
System.out.println(gh);
     if (gh==')')
                break;
    if (gh=='('){
       
            df=y.substring(0,i+1);
            System.out.println(df);
            h=y.substring(i+1, n-1);
            System.out.println(h);
 ty=Double.parseDouble(h);
    System.out.println(ty);}}
       try{
       switch(df){
           
           case("cos("):{m=Math.cos(ty*3.14/180);
                   break;}
           case("sin("):{m=Math.sin(ty*3.14/180);
                   break;}
           case("sqrt("):{m=Math.sqrt(ty);
                   break;}
           case("sinh("):{m=Math.sinh(ty*3.14/180);
                   break;}
           case("tan("):{m=Math.tan(ty*3.14/180);
                   break;}
           case("tanh("):{m=Math.tanh(ty*3.14/180);
                   break;}
           case("degr("):{m=Math.toDegrees(ty);
                   break;}
           case("ln("):{m=Math.log(ty);
                   break;}
           case("exp("):{m=Math.exp(ty);
                   break;}
           
           case("log("):{m=Math.log10(ty);
                   break;}
       
       
           
}}
       catch(ArithmeticException ex){
               }
       System.out.println(m);
               
return m;


}}
