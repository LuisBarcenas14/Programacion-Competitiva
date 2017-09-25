import java.io.*;
import java.util.ArrayList;

public class COJ3319 {

    private static final long[] primos = new long[51];

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> criba = criba(51);
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(bf.readLine());
            System.out.println(primos[a]);
        }
    }

    public static ArrayList<Integer> criba(int n) {

        boolean[] lista = new boolean[n + 1];
        ArrayList<Integer> criba = new ArrayList();
        primos[1] = 1;
        primos[2] = 2;
        int i, j, p = 2;
        for (i = 2; i < n; i++) {
            lista[i] = true;
        }
        lista[0] = lista[1] = false;
        for (i = 2; i < n; i++) {
            int q = p-1;
            if (lista[i]) {    
                primos[p] = i * primos[q];
                criba.add(i);
                for (j = i * i; j <= n; j += i) {
                    lista[j] = false;
                }
            } else {
                primos[p] = primos[q];
            }
            p++;
        }
        return criba;
    }

}