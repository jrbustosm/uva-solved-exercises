/* 

Integer Inquiry

Jose Ricardo Bustos Molina

*/

import java.math.BigInteger;
import java.util.Scanner;

class uva424{

  public static void main(String[] args){
    try{
      Scanner in = new Scanner(System.in);
      BigInteger zero = new BigInteger("0");
      BigInteger sum = new BigInteger("0");
      BigInteger b = in.nextBigInteger();
      while(!b.equals(zero)){
        sum = sum.add(b);
        b = in.nextBigInteger();
      }
      System.out.println(sum);
    }catch(Exception e){}
  }

}
