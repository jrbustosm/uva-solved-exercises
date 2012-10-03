/* 

If We Were a Child Again

Jose Ricardo Bustos Molina

*/

import java.math.BigInteger;
import java.util.Scanner;

class uva10494{

  public static void main(String[] args){
    try{
      Scanner in = new Scanner(System.in);
      while(in.hasNext()){
        BigInteger a = in.nextBigInteger();
        char op = in.next().charAt(0);
        BigInteger b = in.nextBigInteger();
        BigInteger c;
        if(op == '/') c = a.divide(b);
        else c = a.mod(b);
        System.out.println(c);
      }
    }catch(Exception e){
    }
  }

}
