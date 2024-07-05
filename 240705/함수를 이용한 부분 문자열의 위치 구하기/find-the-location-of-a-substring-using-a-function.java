import java.util.Scanner;

public class Main {
    public static String s;
    public static String s1;

    public static int ans(){
        int sl=s.length();
        int s1l=s1.length();
        int answer=-1;

        for(int i=0;i<sl;i++){
            if(s.charAt(i)!=s1.charAt(0)){
                answer=-1;
                continue;
            }
            answer=i;
            //System.out.println(answer);
            int temp=i;
            boolean chk=true;

            for(int j=1;j<s1l;j++){
                temp++;

                if(temp>=sl){
                    return -1;
                }

                //System.out.println(s.charAt(temp)+" "+s1.charAt(j));

                if(s.charAt(temp)!=s1.charAt(j)){
                    answer=-1;
                    chk=false;
                    break;
                }
            }

            if(chk==true) return answer;

            //System.out.println("-- "+answer);
        }

        return answer;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        s=sc.next();
        s1=sc.next();

        System.out.print(ans());
    }
}