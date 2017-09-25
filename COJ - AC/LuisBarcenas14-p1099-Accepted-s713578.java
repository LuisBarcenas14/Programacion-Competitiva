import java.util.*;

public class COJ1099 {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        while (true) {
            int a = in.nextInt();
            if (a == 0) {
                break;
            }
            int b = in.nextInt();
            int c = in.nextInt();
            if ((a > b) && (a > c)) {
                if (a * a == b * b + c * c) {
                    System.out.println("right");
                } else {
                    System.out.println("wrong");
                }
            } else if ((b > a) && (b > c)) {
                if (b * b == a * a + c * c) {
                    System.out.println("right");
                } else {
                    System.out.println("wrong");
                }
            } else if ((c > a) && (c > b)) {
                if (c * c == b * b + a * a) {
                    System.out.println("right");
                } else {
                    System.out.println("wrong");
                }
            }
        }
    }
}