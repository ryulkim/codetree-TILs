public class Main {
    public static void main(String[] args) {
        int a=5, b=6, c=7;
        int temp=a;
        a=c;
        c=b;
        b=temp;
        System.out.printf("%d\n%d\n%d",a,b,c);
    }
}