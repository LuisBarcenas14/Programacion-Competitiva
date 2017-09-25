import java.io.*;

public class JavaApplication7 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n,s,t,i=0;
        t = Integer.parseInt(bf.readLine());
        while(i<t){
            s=0;
            n = Integer.parseInt(bf.readLine());
            while(n>=5){
                n/=5;
                s+=n;
            }
            System.out.println(s);
            i++;
        }
    } 
}