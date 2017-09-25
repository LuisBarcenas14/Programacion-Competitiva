import java.util.Scanner;

public class JavaApplication7 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n,s,t,i=0;
        t = in.nextInt();
        while(i<t){
            s=0;
            n = in.nextInt();
            while(n>=5){
                n/=5;
                s+=n;
            }
            System.out.println(s);
            i++;
        }
    }
    
}