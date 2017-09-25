import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class COJ2196EvenOdd {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        String s;
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out,true);
        int k = Integer.parseInt(bf.readLine());
        for (int i = 0; i < k; i++) {
            s = bf.readLine();
            if(s.endsWith("1")||s.endsWith("3")||s.endsWith("5")||s.endsWith("7")||s.endsWith("9")){
                System.out.println("odd");
            }else{
                System.out.println("even");
            }
        }
    }
    
}