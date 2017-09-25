import java.util.*;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        while (true) {
            String b = in.next();
            if(b.equals("42"))
                break;
            System.out.println(b);
        }
    }
}