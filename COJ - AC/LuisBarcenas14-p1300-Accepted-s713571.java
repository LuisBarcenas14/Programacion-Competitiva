import java.util.*;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int[] a = new int[10];
        int[] b = new int[10];
        int[] c = new int[10];
        int t = 10, cont = 0, y = 0;
        for (int i = 0; i < t; i++) {
            a[i] = in.nextInt();
        }

        for (int i = 0; i < t; i++) {
            b[i] = a[i] % 42;
        }

        for (int i = 0; i < t - 1; i++) {
            for (int j = i + 1; j < t; j++) {
                if (b[i] == b[j]) {
                    y++;
                    break;
                }
            }
        }
        System.out.println(t - y);
    }
}