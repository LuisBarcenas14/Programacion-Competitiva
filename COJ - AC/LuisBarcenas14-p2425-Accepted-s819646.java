import java.io.*;

public class COJ2425Exponent {

    public static double logBase(int coef, int exp) {
        return exp * Math.log(coef);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = 0, bm = 0, em = 0;
        while(true) {
            n = Integer.parseInt(bf.readLine());
            if(n==0) break;
            double mayor = 0;
            for (int i = 0; i < n; i++) {
                String s = bf.readLine();
                String sb[] = s.split(" ");
                int b = Integer.parseInt(sb[0]);
                int e = Integer.parseInt(sb[1]);
                double v = logBase(b, e);
                if (v > mayor) {
                    mayor = v;
                    bm = b;
                    em = e;
                }
            }
            System.out.println(bm+" "+em);
        }
    }
}