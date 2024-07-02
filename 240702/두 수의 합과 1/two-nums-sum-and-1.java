import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();

        String s=Integer.toString(a+b);
        int len=s.length();
        int sum=0;

        for(int i=0;i<len;i++){
            if(s.charAt(i)=='1'){
                sum++;
            }
        }

        System.out.println(sum);
    }
}