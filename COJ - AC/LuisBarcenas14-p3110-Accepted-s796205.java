import java.util.*;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        StringBuilder sb = new StringBuilder();
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < n*2; i++) {
            sb.append("1");
        }
        for (int i = sb.length(); i > 2; i = i - 3) {
            r.append("7");

        }
        switch (sb.length() % 3) {
            case 1:
                r.insert(0, "1");
                break;
            case 2:
                r.insert(0, "3");
                break;
        }
        System.out.println(r);
    }
}
