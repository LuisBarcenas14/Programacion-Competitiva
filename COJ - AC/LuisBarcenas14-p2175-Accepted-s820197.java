
import java.io.*;

public class COJ2175PrimeNumbersAgain {

    public static int MAX = 100050;

    public static int[] generarCriba() {
        int[] criba = new int[MAX + 1];
        int i, j;
        for (i = 2; i * i <= MAX; i++) {
            if (criba[i] == 0) {
                for (j = i * i; j < MAX; j += i) {
                    if (criba[j] == 0) {
                        criba[j] = i;
                    }
                }
            }
        }
        criba[0] = 1;
        criba[1] = 1;
        return criba;
    }

    public static void intervaloP(int[] criba, int a) {
        int may = 0, men = 0;
        boolean b1 = false, b2 = false;
        for (int i = a, j = a; i < criba.length - 1 && j > 0; i++, j--) {
            if (criba[i] == 0 && b1 == false) {
                may = i;
                b1 = true;
            }
            if (criba[j] == 0 && b2 == false) {
                men = j;
                b2 = true;
            }
            if (b1 == true && b2 == true) {
                break;
            }
        }
        System.out.println(men + " " + may);
    }

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int[] criba = generarCriba();
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(bf.readLine());
            intervaloP(criba, a);
        }
    }
}
