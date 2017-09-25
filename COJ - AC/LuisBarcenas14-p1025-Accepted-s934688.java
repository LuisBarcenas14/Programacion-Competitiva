import java.io.*;
import java.util.Arrays;

public class COJ1025DemocracyInDanger {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(bf.readLine());
        int[] ar = new int[k];
        String[] a = bf.readLine().split(" ");
        for (int i = 0; i < k; i++) {
            ar[i] = Integer.parseInt(a[i]);
        }
        Arrays.sort(ar);
        int sum = 0;
        for (int i = 0; i <= k / 2; i++) {
            sum+= (ar[i]/2+1);
        }
        System.out.println(sum);
    }

}