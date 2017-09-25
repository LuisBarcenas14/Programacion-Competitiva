import java.util.Scanner;

public class COJ3044DiceGame {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a11 = in.nextInt();
        int a12 = in.nextInt();
        int b11 = in.nextInt();
        int b12 = in.nextInt();
        int a21 = in.nextInt();
        int a22 = in.nextInt();
        int b21 = in.nextInt();
        int b22 = in.nextInt();
        int sum1 = a11+a12+b11+b12;
        int sum2 = a21+a22+b21+b22;
        if(sum1==sum2){
            System.out.println("Tie");
        }else if(sum1>sum2){
            System.out.println("Gunnar");
        } else if (sum1<sum2){
            System.out.println("Emma");
        }
    }
    
}