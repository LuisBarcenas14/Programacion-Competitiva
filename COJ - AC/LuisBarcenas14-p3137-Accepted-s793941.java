import java.util.*;
public class Main{

    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i=0;i<n;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            boolean band=false;
            if(a+b==c||a-b==c||a*b==c) band=true;
            if(b!=0&&(a/b==c||a%b==c)) band = true;
            if(band==true) System.out.println("YES");
            else System.out.println("NO");
        }
    }    
}