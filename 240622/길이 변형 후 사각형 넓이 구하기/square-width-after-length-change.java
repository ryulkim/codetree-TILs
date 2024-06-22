import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int r=sc.nextInt();
        int c=sc.nextInt();

        r+=8;
        c*=3;

        System.out.println(r);
        System.out.println(c);
        System.out.println(r*c);
    }
}