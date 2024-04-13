import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        String s=sc.next();
        String c=sc.next();
        int idx=s.indexOf(c);

        if(idx==-1){
            System.out.print("No");
        }
        else{
            System.out.print(idx);
        }
        
    }
}