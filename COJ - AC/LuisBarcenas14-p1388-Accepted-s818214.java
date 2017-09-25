import java.util.*;

public class COJ1388LastDigitOfAB {

    /**
     * @param a
     * @param b
     * @param args the command line arguments
     */
    public static void mod4(int a, int b) {
        int d = a % 10;
        int c = b % 4;
        if (b == 0) {
            System.out.println("1");
        } else {
            switch (d) {
                case 1:
                    System.out.println("1");
                    break;
                case 2:
                    switch (c) {
                        case 1:
                            System.out.println("2");
                            break;
                        case 2:
                            System.out.println("4");
                            break;
                        case 3:
                            System.out.println("8");
                            break;
                        case 0:
                            System.out.println("6");
                            break;
                    }
                    break;
                case 3:
                    switch (c) {
                        case 1:
                            System.out.println("3");
                            break;
                        case 2:
                            System.out.println("9");
                            break;
                        case 3:
                            System.out.println("7");
                            break;
                        case 0:
                            System.out.println("1");
                            break;
                    }
                    break;
                case 4:
                    switch (c) {
                        case 1:
                            System.out.println("4");
                            break;
                        case 2:
                            System.out.println("6");
                            break;
                        case 3:
                            System.out.println("4");
                            break;
                        case 0:
                            System.out.println("6");
                            break;

                    }
                    break;
                case 5:
                    System.out.println("5");
                    break;
                case 6:
                    System.out.println("6");
                    break;
                case 7:
                    switch (c) {
                        case 1:
                            System.out.println("7");
                            break;
                        case 2:
                            System.out.println("9");
                            break;
                        case 3:
                            System.out.println("3");
                            break;
                        case 0:
                            System.out.println("1");
                            break;
                    }
                    break;
                case 8:
                    switch (c) {
                        case 1:
                            System.out.println("8");
                            break;
                        case 2:
                            System.out.println("4");
                            break;
                        case 3:
                            System.out.println("2");
                            break;
                        case 0:
                            System.out.println("6");
                            break;
                    }
                    break;
                case 9:
                    switch (c) {
                        case 1:
                            System.out.println("9");
                            break;
                        case 2:
                            System.out.println("1");
                            break;
                        case 3:
                            System.out.println("9");
                            break;
                        case 0:
                            System.out.println("1");
                            break;
                    }
                    break;
                case 0:
                    System.out.println("0");
                    break;
            }
        }
    }

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            mod4(a, b);
        }
    }
}
