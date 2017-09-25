import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class COJ2683BaseB {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BigInteger bi;
        int t = Integer.parseInt(bf.readLine());
        int b;
        String s;
        String a[];
        while(t-- >0){
            s = bf.readLine();
            a = s.split(" ");
            bi = new BigInteger(a[0]);
            b = Integer.parseInt(a[1]);
            System.out.println(bi.toString(b).toUpperCase());
        }
    }
    
}