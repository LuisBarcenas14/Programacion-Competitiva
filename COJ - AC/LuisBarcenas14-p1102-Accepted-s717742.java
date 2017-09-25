import java.math.BigInteger;
import java.util.Scanner;

public class PruebaBigInteger {

    public static void main(String[] args) {
        // TODO code application logic here
        BigInteger b1, b2, b3, b4;
        Scanner in = new Scanner(System.in);
        while (true) {
            String a = in.next();
            if (a.equals("0")) {
                break;
            }

            b1 = new BigInteger(a);
            b2 = new BigInteger("11");
            b3 = new BigInteger("0");
            b4 = b1.mod(b2);

            if (b4.compareTo(b3) == 0) {
                System.out.printf("%s is a multiple of 11.\n",a);
            } else {
                System.out.printf("%s is not a multiple of 11.\n",a);
            }
        }

    }
}