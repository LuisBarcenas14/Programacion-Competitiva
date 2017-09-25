import java.io.*;

public class SumaDigitos {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String n = bf.readLine();
        int nu = Integer.parseInt(n) ;
        for (int z = 0; z < nu; z++) {
            String s = bf.readLine();
            int l = s.length();
            int sum = 0, sPar = 0, sImpar = 0;
            for (int i = 0, j = 1; i < l; i++, j++) {
                int a = s.charAt(i) - 48;
                sum += a;
                if (i % 2 == 0) {
                    sPar += a;
                } else {
                    sImpar += a;
                }
            }
            if ((sum % 3 == 0) && (sPar - sImpar == 0) && ((s.charAt(--l) - 48) % 5 == 0)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            //System.out.println(sum);
        }
    }
}