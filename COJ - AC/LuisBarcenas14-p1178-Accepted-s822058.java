import java.util.*;
import java.io.*;

public class COJ1178Shopalic {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            int m = Integer.parseInt(bf.readLine());
            int[] a = new int[m];
            String s = bf.readLine();
            String[] num = s.split(" ");
            int sum = 0;
            for (int j = 0; j < a.length; j++) {
                a[j] = Integer.parseInt(num[j]);
            }
            Arrays.sort(a);
            for (int k = a.length - 1, j = 0; k+1 >= 0; k -= 3, j++) {
                if (j > 0) {
                    sum += a[k + 
                            1];
                }
            }
            System.out.println(sum);
        }
    }
}