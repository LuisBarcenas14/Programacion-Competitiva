import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class COJ1195BasicallySpeaking {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s,s2;
        String p[];
        BigInteger bi;
        int n;
        while((s = bf.readLine())!=null){
            s= "h "+s;
            p = s.split("\\s+");
            bi = new BigInteger(p[1],Integer.parseInt(p[2]));
            s2 = bi.toString(Integer.parseInt(p[3]));
            n = s2.length();
            if(n>7){
                System.out.println("  ERROR");
            }else{
                for (int i = 0; i < 7-n; i++) {
                    System.out.print(" ");
                }
                System.out.print(s2.toUpperCase()+'\n');
            }
        }
    }  
}