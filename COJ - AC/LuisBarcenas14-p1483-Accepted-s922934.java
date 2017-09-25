import java.io.*;

public class COJ1483 {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] l = bf.readLine().split(" ");
        if (l[0].equals("rectangle")) {
            int a = Integer.parseInt(l[1]);
            int b = Integer.parseInt(l[2]);
            System.out.println(a * b);
        } else {
            int a = Integer.parseInt(l[1]);
            System.out.println(a * a);
        }
    }
}