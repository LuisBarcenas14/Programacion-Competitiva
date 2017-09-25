import java.io.*;

public class COJ1259Div4Base3 {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        int a = 0;
        for (int i = 0; i < n; i++) {
            String s = bf.readLine();
            div4(s);
        }
    }

    public static void div4(String s) {
        int a = 0;
        s = s.trim();
        int[] div = new int[4];
        div[0] = 7;
        div[1] = 9;
        div[2] = 3;
        div[3] = 1;
        int tam = s.length();
        int m = tmod4(s);
        int sum = 0;
        if (m == 1) {
            m = 3;
        } else if (m == 3) {
            m = 1;
        }
        for (int i = 0, j = m; i < tam; i++, j++) {
            j %= 4;
            int c = (s.charAt(i) - 48);
            sum += c * div[j];
        }
        if (sum % 4 == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static int tmod4(String s) {
        int tam = s.length();
        int m = 0;
        if (tam > 99) {
            String st = Integer.toString(tam);
            String sbst = st.substring(st.length() - 2);
            int b = Integer.parseInt(sbst);
            m = b % 4;
        } else {
            m = tam % 4;
        }
        return m;
    }

}