import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();
        String s=sc.next();
        int cnt=0;

        for(int i=0;i<n;i++){
            String temp=sc.next();
            if(s.equals(temp)){
                cnt++;
            }
        }

        System.out.print(cnt);
    }
}