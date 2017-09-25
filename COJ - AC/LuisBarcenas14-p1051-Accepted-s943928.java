import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class COJ1051Div3 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        Integer n = Integer.parseInt(bf.readLine());
        int f = (n / 3 * 2);
        int mod = n % 3;
        switch (mod) {
            case 0:
            case 1:
                pw.println(f);
                break;
            case 2:
                pw.println((f + 1));
        }
    }

}