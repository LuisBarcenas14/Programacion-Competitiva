import java.util.*;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int s = a + b + c;
        if (a > (b + c)) {
            System.out.println(b + c + 1);
        } else if (b > (a + c)) {
            System.out.println(a + c + 1);
        } else if (c > a + b) {
            System.out.println(a + b + 1);
        } else {
            if (s % 2 == 0) {
                System.out.println(s / 2 + 1);
            } else if ((a + b + c) % 2 == 1) {
                System.out.println(s % 2 + 2);
            }
        }
    }
}