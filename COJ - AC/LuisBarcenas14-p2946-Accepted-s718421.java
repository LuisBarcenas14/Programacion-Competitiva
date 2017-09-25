import java.util.Scanner;

public class COJ2946InvertingTheParity {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int a = in.nextInt();
            int res = a % 2;
            if (res == 1) {
                int pr = a * 2;
                System.out.println(pr);
            } else if (res == 0) {
                int coc = a;
                while (res == 0) {
                    coc = coc / 2;
                    res = coc % 2;
                }
                System.out.println(coc);
            }
        }
    }
}