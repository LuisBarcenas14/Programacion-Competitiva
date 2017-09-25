import java.util.Scanner;

public class COJ2413Div5 {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            String a = in.next();
            char c1 = a.charAt(a.length() - 1);
            int c2 = c1 - 48;
            if ((c2 == 5) || (c2 == 0)) {
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}