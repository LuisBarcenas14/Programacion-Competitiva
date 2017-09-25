import java.util.*;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int f = (n / 3 * 2);
        int mod = n % 3;
        switch (mod) {
            case 0:
            case 1:
                System.out.println(f);
                break;
            case 2:
                System.out.println((f + 1));
        }
    }
}