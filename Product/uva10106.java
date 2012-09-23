/* 

Product

Jose Ricardo Bustos Molina

*/

import java.math.BigInteger;
import java.util.Scanner;

class uva10106{

  public static void main(String[] args){
    try{
      Scanner in = new Scanner(System.in);
      while(in.hasNext()){
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        BigInteger c = a.multiply(b);
        System.out.println(c);
      }
    }catch(Exception e){}
  }

}
