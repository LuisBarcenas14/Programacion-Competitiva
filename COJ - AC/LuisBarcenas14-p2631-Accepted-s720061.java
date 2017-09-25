import java.util.*;

public class COJ2631UnlockMySafe {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        String[] a = {"1", "2", "3", "4", "5", "6", "7", "8"};
        int t = in.nextInt();
        for (int j = 0; j < t; j++) {
            int b = in.nextInt();
            int r = b;
            int n = 1;
            for (int i = b; i > 0; i--) {
                n *= i;
            }
            //System.out.println(n/r);
            Perm2(a, "", b, r, n);
        }
    }

    private static int num = 0;

    private static void Perm2(String[] elem, String act, int t, int r, int n) {

        if (t == 0) {
            if (num == n / 3) {
                System.out.println(act);
            }
            num++;
            if(num==n)
                num=0;
        } else {
            for (int i = 0; i < r; i++) {
                if (!act.contains(elem[i])) { // Controla que no haya repeticiones
                    Perm2(elem, act + elem[i], t - 1, r, n);
                }
            }
        }
    }

}