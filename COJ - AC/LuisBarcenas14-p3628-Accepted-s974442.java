import java.io.*;

public class COJ3628Acronyms {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String s;
        String[] c;
        String[] c2;
        int n;
        String p1,p2;
        while((s = bf.readLine())!=null){
            p1=p2="";
            c = s.split(" ");
            n = c.length;
            for (int i = 0; i < n; i++) {
                p1+=c[i].charAt(0);
            }
            s = bf.readLine();
            c = s.split(" ");
            n = c.length;
            for (int i = 0; i < n; i++) {
                p2+=c[i].charAt(0);
            }
            if(p1.equals(p2)){
                System.out.println("yes");
            }else{
                System.out.println("no");
            }
        }
    }  
}