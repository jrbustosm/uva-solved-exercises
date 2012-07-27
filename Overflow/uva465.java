/* 

Overflow

Jose Ricardo Bustos Molina

*/

import java.math.BigInteger;
import java.util.Scanner;

class uva465{

  public static void main(String[] args){
    try{
      Scanner in = new Scanner(System.in);
      BigInteger max = new BigInteger("2147483647");
      while(in.hasNext()){
        String line = in.nextLine();
        System.out.println(line);
        String[] nums;
        boolean sum;
        if(line.indexOf("+")!=-1){
          sum = true;
          nums = line.split("\\+");
        }else{
          sum = false;
          nums = line.split("\\*");
        }
        BigInteger a = new BigInteger(nums[0].trim());
        if(a.compareTo(max) > 0) System.out.println("first number too big");
        BigInteger b = new BigInteger(nums[1].trim());
        if(b.compareTo(max) > 0) System.out.println("second number too big");
        BigInteger c;
        if(sum) c = a.add(b);
        else c = a.multiply(b);
        if(c.compareTo(max) > 0) System.out.println("result too big");
      }
    }catch(Exception e){}
  }

}
