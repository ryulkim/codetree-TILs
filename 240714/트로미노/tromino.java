import java.util.Scanner;

public class Main {
    static int n,m;

    public static boolean valid(int i, int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        int arr[][]=new int[205][205];
        int ox[]={0, 1, -1, 0, -1, 0};
        int oy[]={-1, 0, 0, -1, 0, -1};
        int tx[]={1, 0, 0, -1, 1, 0};
        int ty[]={0, 1, 1, 0, 0, 1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=sc.nextInt();
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                for(int k=0;k<6;k++){
                    int sum=0;

                    int tmx=i+ox[k];
                    int tmy=j+oy[k];
                    if(!valid(tmx, tmy)) continue;
                    sum+=arr[tmx][tmy];

                    tmx=i+tx[k];
                    tmy=j+ty[k];
                    if(!valid(tmx, tmy)) continue;
                    sum+=arr[tmx][tmy];
                    sum+=arr[i][j];

                    if(sum>ans){
                        ans=sum;
                    }

                }
            }
        }

        System.out.print(ans);
    }
}