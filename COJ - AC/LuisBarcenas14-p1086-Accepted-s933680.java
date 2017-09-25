import java.io.*;

public class COJ1086 {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        int n = 4567890;
        boolean[] criba = criba(n);
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        for(int i =0;i<10;i++){
            int a = Integer.parseInt(bf.readLine());
            int b =contarPrimos(a,criba);
            System.out.println(b);
        }
    }

    public static boolean[] criba(int n) {
        boolean[] lista = new boolean[n + 1];
        int i, j;
        for (i = 2; i < n; i++) {
            lista[i] = true;
        }
        lista[0] = lista[1] = false;
        for (i = 2; i * i <= n; i++) {
            if (lista[i]) {
                for (j = i * i; j <= n; j += i) {
                    lista[j] = false;
                }
            }
        }
        return lista;
    }

    public static int contarPrimos(int n, boolean[] criba) {
        int a = 0;
        for (int i = 2; i <= n; i++) {
            if (criba[i] == true) {
                a++;
            }
        }
        return a;
    }

}