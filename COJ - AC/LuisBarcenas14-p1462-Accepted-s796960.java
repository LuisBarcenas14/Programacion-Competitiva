import java.util.*;
public class COJ1462EasySum {

    static int modulo(String n) {
        int x, mod = 0;
        for (x = 0; x < n.length(); x++) {
            mod = (mod * 10 + (n.charAt(x) - '0')) % 128;
        }
        return mod;
    }

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int mod = modulo(in.next());
            sum = (sum + mod) % 128;
        }
        System.out.println(sum);
    }
}