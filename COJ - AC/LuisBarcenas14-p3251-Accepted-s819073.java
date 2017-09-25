import java.io.*;
import java.util.Arrays;

public class COJ3251Cesta {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        long tiempo = System.currentTimeMillis();
        ejecutaProceso();
        long tiempof = System.currentTimeMillis();
        tiempof -= tiempo;
        //System.out.println(tiempof);
    }

    static void ejecutaProceso() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String linea = bf.readLine();
        char[] ch = linea.toCharArray();
        Arrays.sort(ch);
       for(int i=ch.length-1;i>=0;i--){
           System.out.print(ch[i]);
       }
        //System.out.println(ch);
    }
}