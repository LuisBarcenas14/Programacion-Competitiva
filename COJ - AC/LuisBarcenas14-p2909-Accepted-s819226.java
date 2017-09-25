import java.io.*;

public class COJ2909TobbyAndTheDivisorsI {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int z = Integer.parseInt(bf.readLine());
        int n = 2500;
        int[] c = new int[n + 1];
        c = c2500(n);
        int[] d = new int[n + 1];
        d = d2500(c, n);
        for(int i =0;i<z;i++){
            int a = Integer.parseInt(bf.readLine());
            System.out.println(d[a]);
        }
    }

    public static int calcNoDivisores(int a) {
        double r = Math.sqrt(a);
        boolean band = false;
        int sum = 0;
        if (r % 1 == 0) {
            band = true;
        }
        int rn = (int) (r);
        for (int j = 1; j <= rn; j++) {
            if (a % j == 0) {
                sum++;
            }
        }
        sum *= 2;
        if (band == true) {
            sum--;
        }
        return sum;
    }

    public static int[] c2500(int n) {
        int c[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            c[i] = calcNoDivisores(i);
        }
        return c;
    }

    public static int[] d2500(int[] c, int n) {
        int[] d = new int[n + 1];
        d[0] = 0;
        int ct = 0;
        int it = 0;
        for (int i = 1, j = 0; i <= n; i++, j++) {
            if (c[i] > ct) {
                d[i] = i;
                ct = c[i];
                it = i;
            }else{
                d[i] = it;
            }
        }
        return d;
    }

    public static long calcularTiempo() {
        long tiempo = System.currentTimeMillis();
        //PROCESO
        long tiempof = System.currentTimeMillis();
        tiempof -= tiempo;
        return tiempof;
    }
    
    public static void imprimirResultados(){
        int n = 0;
        int[] c = new int[n + 1];
        c = c2500(n);
        System.out.println("-----------------------------------C---------------------------------------------");
        for (int i = 1; i <= n; i++) {
            //int b = calcNoDivisores(i);
            //System.out.println(i + ": " + b);
            System.out.println(i + ": " + c[i]);
        }
        System.out.println("-----------------------------------D---------------------------------------------");
        int[] d = new int[n + 1];
        d = d2500(c, n);
        for (int i = 1; i <= n; i++) {
            //int b = calcNoDivisores(i);
            //System.out.println(i + ": " + b);
            System.out.println(i + ": " + d[i]);
        }
    }
}

