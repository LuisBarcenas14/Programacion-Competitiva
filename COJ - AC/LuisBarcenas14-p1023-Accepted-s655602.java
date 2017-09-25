import java.util.*;
class Main{
	public static void main(String [] args){
		Scanner in = new Scanner (System.in);
		String a;
		double sum=0;
		for(int i=0; i<12; i++){
			a = in.next();
			double num = Double.parseDouble(a);
			sum+=num;
		}
		System.out.println("$"+(Math.rint( sum/12*100)/100));
	}
}
