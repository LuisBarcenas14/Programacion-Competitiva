import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        BigInteger b1, b2, b3, b4;
        b4 = new BigInteger("1000000000");
        String d = "1000000000";
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            String a = in.next();
            String b = in.next();
            if (((a.length() > 9) || b.length() > 9) && ((a.compareTo(d) != 0) && b.compareTo(d) != 0)) {
                System.out.println("0");
            } else {
                //b2 = in.nextBigInteger();
                b1 = new BigInteger(a);
                b2 = new BigInteger(b);
                b3 = b1.modPow(b2,b4);
                System.out.println(b3);
            }
        }
    }
}