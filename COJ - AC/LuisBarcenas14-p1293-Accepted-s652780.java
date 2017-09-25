import java.util.*;
import java.util.Scanner;
import java.math.BigInteger;


class Main{
	public static void main(String [] args){
		Scanner in = new Scanner (System.in);
		BigInteger b1,R;
		b1 = new BigInteger("2");
		int N = in.nextInt();
		R = b1.pow(N);
		System.out.println(R);
	}
}
