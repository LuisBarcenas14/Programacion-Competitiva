import java.io.*;

public class COJ1306Div4 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            multiplo4(bf.readLine());
        }
    }

    public static void multiplo4(String a) {
        int t = a.length();
        if (t < 2) {
            esMultiplo4(Integer.parseInt(a));
        } else {
            int b = Integer.parseInt(a.substring(t-2, t));
            esMultiplo4(b);
        }
    }

    public static void esMultiplo4(int a) {
        if (a % 4 == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

}