import java.util.*;
import java.math.BigInteger;
public class COJ1306 {
    public static void main(String[] args) {
        // TODO code application logic here
           Scanner in = new Scanner (System.in);
        int T = in.nextInt();
        BigInteger a[] = new BigInteger[T];
        BigInteger res[] = new BigInteger[T];
        for(int i=0;i<T;i++){
           a[i] = in.nextBigInteger();
           BigInteger I=new BigInteger("4");
           res[i]=a[i].mod(I);
        }
         for(int i=0;i<T;i++){;
            if((res[i].equals(new BigInteger("0"))))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
    
}
