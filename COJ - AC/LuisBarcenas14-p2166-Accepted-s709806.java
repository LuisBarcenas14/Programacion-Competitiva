import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int n, k, cont = 0;
        for (int i = 0; i < t; i++) {
            n = in.nextInt();
            k = in.nextInt();
            int[] a = new int[n]; //[k] [n] k>
            for (int j = 0; j < a.length; j++) {
                a[j] = in.nextInt();
            }
            for (int z = 0; z < a.length; z++) {
                if ((a[z] >= a[k - 1]) && (a[z] != 0)) {
                    cont++;
                }
            }
            System.out.println(cont);
            cont = 0;
        }
    }
}