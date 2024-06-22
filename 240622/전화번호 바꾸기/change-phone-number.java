import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        sc.useDelimiter("-");
        String f=sc.next();
        int x=sc.nextInt();
        int y=sc.nextInt();

        System.out.print(f+"-"+y+"-"+x);
    }
}