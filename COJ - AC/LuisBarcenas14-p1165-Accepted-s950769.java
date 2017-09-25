import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class COJ1165GuessTheNumber {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        //pw.println(lcm(12, 5));
        char c[];
        long l;
        String s;
        boolean band;
        while (!(s = bf.readLine()).equals("*")) {
            c = s.toCharArray();
            l=1;
            band=false;
            for (int i = 0; i < c.length; i++) {
                if( c[i]=='Y'){  l = lcm((i+1), l); }else{ if( lcm((i+1),l) == l ){ band=true; break; } }
            }
            if(!band){
                for (int i = 0; i < c.length; i++) {
                    if( c[i]=='N'){  if( lcm((i+1),l) == l ){ band=true; break; } }
                }
            }
            if(band){
                pw.println("-1");
            }else{
                pw.println(l);
            }
        }
    }

    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

}