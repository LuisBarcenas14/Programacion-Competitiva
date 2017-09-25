import java.util.*;

public class COJ2948 {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int n = 0; n < t; n++) {
            int sum = 0, sum2 = 0;
            String c = in.next();
            for (int i = 0; i <= c.length()-1; i++) {
                sum += c.charAt(i) - 48;
            }
            while(sum>9){
            String d = String.valueOf(sum);
            sum=0;
            for (int j = 0; j <= d.length()-1; j++) {
                sum += d.charAt(j) - 48;
            }
            }
            System.out.println(sum);
        }
    }
}