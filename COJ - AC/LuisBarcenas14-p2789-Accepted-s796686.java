import java.io.*;
public class COJ2789SumOrder {
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String linea = bf.readLine();
        int n = linea.length();
        int[] cont = new int[3];
        for (int i = 0; i < n; i++) {
            switch (linea.charAt(i)) {
                case '1':
                    cont[0]++;
                    break;
                case '2':
                    cont[1]++;
                    break;
                case '3':
                    cont[2]++;
                    break;
            }
        }
        for (int i = 0, z = 0; i < 3; i++) {
            for (int x = 0; x < cont[i]; x++) {
                if (z < n-1) {
                    System.out.print((i + 1) + "+");
                } else {
                    System.out.print((i + 1));
                }
                z+=2;
            }
        }
    }
}