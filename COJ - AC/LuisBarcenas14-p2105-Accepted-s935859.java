import java.io.*;

public class COJ2105IslandCoast {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] l = bf.readLine().split(" ");
        int n = Integer.parseInt(l[0]); //ALTO
        int m = Integer.parseInt(l[1]); //LARGO
        char[][] mapa = new char[n][m];
        for (int i = 0; i < n; i++) {
            mapa[i] = bf.readLine().toCharArray();
//            for (int j = 0; j < m; j++) {
//                
//            }
            //char b = (char) bf.read();
        }
        int t =contarOrillas(mapa, n, m);
        System.out.println(t);
    }

    public static int contarOrillas(char[][] mapa, int n, int m) {
        int t = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (mapa[i][j] == '+') {
                    if (mapa[i - 1][j] == '-') { //ARRIBA
                        t++;
                    } else if (mapa[i][j - 1] == '-') { //IZQUIERDA
                        t++;
                    } else if (mapa[i][j + 1] == '-') { //DERECHA
                        t++;
                    } else if (mapa[i + 1][j] == '-') { //ABAJO
                        t++;
                    }
                    //System.out.println("I: "+i+"J: "+j);
                }
            }
        }
        return t;
    }

}
