import java.io.*;
import java.util.ArrayList;

public class COJ1390MaxFactor {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> primos = primos(20000);//20000
        int n = 0;
        while (true) {
            String l1 = bf.readLine();
            if (l1.isEmpty()) {
            }else{
               n = Integer.parseInt(l1);
               break;
            }
        } 
        int[][] a = new int[n][2];
        int mayor = 0, mayor2 = 0;
        for (int i = 0; i < n; i++) {
            String l2 = bf.readLine();
            if (l2.isEmpty()) {
                i--;
                continue;
            }
            a[i][0] = Integer.parseInt(l2.trim());
            a[i][1] = factorMayor(a[i][0], primos);
            if (a[i][1] > mayor) {
                mayor = a[i][1];
                mayor2 = a[i][0];
            }
        }
        System.out.println(mayor2);
    }

    public static ArrayList<Integer> primos(int n) {
        boolean[] criba = new boolean[n + 1];
        ArrayList<Integer> primos = new ArrayList();
        for (int i = 2; i <= n; i++) {
            if (!criba[i]) {
                primos.add(i);
                for (int j = i * i; j <= n; j += i) {
                    criba[j] = true;
                }
            }
        }
        return primos;
    }

    public static int factorMayor(int n, ArrayList<Integer> primos) {
        int f = 0;
        int pf = primos.get(f);
        int mayor = 0;
        while (pf * pf <= n) {
            while (n % pf == 0) {
                n /= pf;
                mayor = pf;
            }
            pf = primos.get(++f);
        }
        if (n != 1) {
            mayor = n;
        }
        return mayor;
    }

}