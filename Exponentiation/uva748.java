/* 

Exponentiation

Jose Ricardo Bustos Molina

*/

import java.math.BigInteger;
import java.util.Scanner;

class uva748{

  public static void main(String[] args){
    try{
      Scanner in = new Scanner(System.in);
      BigInteger b10 = new BigInteger("10");
      while(in.hasNext()){
        String num = in.next();
        if(num.indexOf(".")!=-1){
          while(num.charAt(num.length()-1)=='0'){
            num = num.substring(0,num.length()-1);
          }
        }
        int l = num.indexOf(".");
        int auxl = 0;
        if(l!=-1) l = num.length()-l-1;
        num = num.replace(".","");
        BigInteger a = new BigInteger(num);
        int b = in.nextInt();
        if(l!=-1){
          BigInteger r10 = pow(pow(b10, l), b);
          auxl = r10.toString().length()-1;
        }
        BigInteger c = pow(a,b);
        String out = c.toString();
        auxl = out.length()-auxl;
        if(auxl < 0){
          System.out.print('.');
          for(int i=auxl; i<0; ++i) System.out.print('0');
        }
        for(int i = 0; i<out.length(); ++i){
          if(i==auxl) System.out.print('.');
          System.out.print(out.charAt(i));
        }
        System.out.println();
      }
    }catch(Exception e){
      System.out.println(e);
    }
  }

  public static BigInteger pow(BigInteger a, int b){
    BigInteger p = new BigInteger("1");
    for(int i=0; i<b; ++i) p = p.multiply(a);
    return p;
  } 

}
