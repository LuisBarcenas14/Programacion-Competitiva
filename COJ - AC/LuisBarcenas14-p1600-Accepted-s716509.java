import java.util.*;
import java.math.*;

public class COJ1600BigPowers {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        BigInteger b1, b2, b3, b4;
        while (true) {
            String a = in.next();
            String b = in.next();
            if((a.compareTo("0")==0)&&(b.compareTo("0")==0)){
                break;
            }
            b1 = new BigInteger(a);
            b2 = new BigInteger(b);
            b4 = new BigInteger("10");
            b3 = b1.modPow(b2, b4);
            System.out.println(b3);
        }
    }
}