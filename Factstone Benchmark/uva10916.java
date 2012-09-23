/* 

Factstone Benchmark

Jose Ricardo Bustos Molina

*/

import java.util.Scanner;
import java.math.BigInteger;
import java.util.HashMap;

class uva10916{

  public static void main(String[] args){
    HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
    int[] keys = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    int[] vals = {3,5,8,12,20,34,57,98,170,300,536,966,1754,3210,5910,10944,20366,38064,71421,134480,254016};
    for(int i=0; i<keys.length; ++i) m.put(keys[i], vals[i]);
    Scanner in = new Scanner(System.in);
//    BigInteger TWO = new BigInteger("2");
    int y = in.nextInt();
    while(y!=0){
/* 
      //CON ESTO GENERO LOS NUMEROS DE ARRIBA, SE PUEDE HACER CON LOGARITMOS
      //N! = LOG2(N) + LOG2(N-1) + .... + LOG2(1)
      //Pero me gusta mas quemarlo ;)
  
      int bts = (int)(Math.pow(2d,(y-1940)/10));
      BigInteger max = TWO.pow(bts);
      BigInteger f = new BigInteger("1");
      BigInteger n = new BigInteger("1");
      BigInteger ONE = new BigInteger("1");
      while(f.compareTo(max)==-1){
        n = n.add(ONE);
        f = f.multiply(n);
      }
      n.subtract(ONE);
      System.out.println((y-1940)/10 + " " + n.toString());*/
      System.out.println(m.get((y-1940)/10));
      y = in.nextInt();
    }
  }
}
