import java.util.Scanner;

public class COJ2152SumOfTheDigits {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            String a = in.next();
            int sum = 0;
            int n = a.length();
            if (a.charAt(0) == '-') {
                for (int j = 1; j < n; j++) {
                    sum += a.charAt(j) - 48;
                }
                System.out.println(sum);
            } else {
                for (int j = 0; j < n; j++) {
                    sum += a.charAt(j) - 48;
                }
                System.out.println(sum);
            }
        }

    }
}