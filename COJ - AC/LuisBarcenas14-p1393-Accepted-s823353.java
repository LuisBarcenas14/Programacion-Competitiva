import java.io.*;
import java.math.BigInteger;

public class COJ1393ProfesorCruelDeMat {
    public static void main(String[] args) throws IOException {
        BigInteger b0, b1, b2, b3, b10;
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s = bf.readLine();
        String[] sn = s.split(" ");
        b1 = new BigInteger(sn[0]);
        int i2 = Integer.parseInt(sn[1]);
        b3 = b1.pow(i2);
        String b = b3.toString();
        if(b.length()<=70){
            System.out.println(b);
        }else{
            char[] c = b.toCharArray();
            for(int i=0;i<c.length;){
                for(int j=0;j<70;j++,i++){
                    if(i>=c.length){
                        break;
                    }
                    System.out.print(c[i]);
                }
                System.out.println("");
            }
        }
    }
}