import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        sc.useDelimiter("-");
        String f=sc.next();
        String s=sc.next();

        System.out.print(f+s);
    }
}