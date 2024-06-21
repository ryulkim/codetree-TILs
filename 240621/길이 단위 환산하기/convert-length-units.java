import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        double d;

        d=sc.nextDouble();

        d*=30.48;

        d=Math.round(d*10)/10.0;
        
        System.out.println(d);
    }
}