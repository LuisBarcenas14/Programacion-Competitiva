import java.util.*;

public class Main{

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        for (;;) {
            int c = in.nextInt();
            if(c==0) break;
            String cad = Integer.toBinaryString(c);
            int count = 0;
            for (int i = 0; i < cad.length(); i++) {
                if (cad.charAt(i) == '1') count++;
            }
            System.out.println("The parity of "+cad+" is "+count+" (mod 2).");
        }
    }
}