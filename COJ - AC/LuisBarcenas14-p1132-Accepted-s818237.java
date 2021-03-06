import java.io.*;
public class COJ1132DivisorSummation {
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(bf.readLine());
            double r = Math.sqrt(a);
            boolean band = false;
            int sum = 0;
            int jt = 0;
            if (r % 1 == 0) {
                band = true;
            }
            int rn = (int) (r);
            for (int j = 1; j <= rn; j++) {
                if (a % j == 0) {
                    sum = sum + j + (a / j);
                    jt = j;
                }
            }
            sum -= a;
            if(band == true) sum -= jt;
            System.out.println(sum);
        }
    }
}