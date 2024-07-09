import java.util.*;




public class Main {

    static int n;
    static int m;
    static int arr[][]=new int[105][105];
    static boolean chk[][]=new boolean[105][105];

    public static class Pair{
        int i;
        int j;

        Pair(int i, int j){
            this.i=i;
            this.j=j;
        }
    }

    public static boolean valid(int i, int j){
        return i>=0&&i<n&&j>=0&&j<n;
    }

    public static boolean bfs(){
        Queue<Pair> q=new LinkedList<>();
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        q.add(new Pair(0,0));
        chk[0][0]=true;

        while(q.peek()!=null){
            Pair p=q.poll();
            int r=p.i, c=p.j;

            if(r==n-1&&c==m-1){
                return true;
            }

            for(int k=0;k<4;k++){
                int tx=dx[k]+r;
                int ty=dy[k]+c;

                if(valid(tx,ty)&&chk[tx][ty]==false&&arr[tx][ty]==1){
                    q.add(new Pair(tx,ty));
                    chk[tx][ty]=true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        
        boolean result=bfs();
        if(result==true) System.out.print(1);
        else System.out.print(0);
        
    }
}