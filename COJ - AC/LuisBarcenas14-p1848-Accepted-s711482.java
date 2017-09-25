import java.util.*;

public class COJ1848 {

    public static int fibonacci(int N) {
        if ((N == 0) || (N == 1)) {
            return N;
        } else {
            return fibonacci(N - 1) + fibonacci(N - 2);
        }

    }

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int[] a = new int[t];
        int m = 0, i, j, k;
        for (i = 0; i < t; i++) {
            a[i] = in.nextInt();
            if (a[i] >= m) {
                m = a[i];
            }
        }
        int[] b = new int[m + 1];
        b[0]=1;
        b[1]=1;
        for (j = 2; j <= m; j++) {
            b[j] = (b[j - 2] + b[j - 1])%10000;
        }
        for (k = 0; k < t; k++) {
            int temp = a[k];
            System.out.println(b[temp-3]%10000+" "+b[temp-2]%10000+" "+b[temp-1]%10000);
        }
    }
}