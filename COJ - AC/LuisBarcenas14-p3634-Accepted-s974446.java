import java.io.*;

public class tobbyled {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        for (;;) {
            String l0 = bf.readLine();
            if (l0 == null) {
                break;
            }
            String[] a = l0.split(" ");
            int n = Integer.parseInt(a[0]);
            long t = Long.parseLong(a[1]) % n;
            char d = a[2].charAt(0);
            String l1 = bf.readLine();
            String led = bf.readLine();
            String l2 = bf.readLine();
            int tl = led.length();
            String sled1 = "", sled2 = "";
            int t2 = (int) (t) * 2;
            System.out.println(l1);
            if (d == 'L') {
                sled1 = led.substring(t2, tl - 1);
                sled2 = led.substring(0, t2+1);
                System.out.println(sled1 + sled2);
            } else {
                sled1 = led.substring(tl - t2 -1, tl - 1);
                sled2 = led.substring(0, tl - t2);
                System.out.println(sled1 + sled2);
            }
            System.out.println(l2);
        }
    }
}

/*
10 2 L
+-+
| | | |T|o|b|b|y|!|!|
+-+
4 4 R
+-+
| | | |T|
+-+
*7

 */
