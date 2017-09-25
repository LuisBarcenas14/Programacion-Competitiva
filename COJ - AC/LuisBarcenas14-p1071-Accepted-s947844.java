import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class COJ1071Bishops {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        String l;
        BigInteger bi;
        BigInteger uno = new BigInteger("1");
        BigInteger dos = new BigInteger("2");
        while ((l = bf.readLine()) != null) {
            if (l.equals("1")) {
                pw.println("1");
            } else {
                bi = new BigInteger(l);
                bi = bi.subtract(uno);
                pw.println(bi.multiply(dos));
            }
        }
    }

}