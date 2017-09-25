import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] factorial = {1, 2, 6, 24, 120};

        while(true) {
            int sum = 0, cont = 0;
            String b = in.nextLine();
            if(b.equals("0"))
                break;
            for (int i = b.length() - 1; i >= 0; i--) {
                sum += factorial[cont++] * (b.charAt(i) - 48);
            }
            System.out.println(sum);
        }
    }
}