import java.util.*;
import java.math.BigInteger;

public class COJ1293 {

    public static void main(String[] args) {
        // TODO code application logic here
        BigInteger b1,b2;
        Scanner in = new Scanner (System.in);
        int n = in.nextInt();
        b1 = new BigInteger("2");
        b2 = b1.pow(n);
        System.out.println(b2);
        //System.out.println(String.valueOf(Math.pow(2,100)));
    }
    
}