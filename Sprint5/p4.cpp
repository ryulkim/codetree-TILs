#include <iostream>
using namespace std;

int n,m,q,r1,r2,c1,c2;
int arr[105][105];
int dr[5]={0,0,1,-1};
int dc[5]={1,-1,0,0};

bool valid(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}

void cycle(){
    int temp[105][105];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            temp[i][j]=arr[i][j];
        }
    }

    for(int i=r2;i>r1;i--){
        temp[i][c1]=arr[i-1][c1];
    }

    for(int i=c1;i<c2;i++){
        temp[r1][i]=arr[r1][i+1];
    }
    
    for(int i=r1;i<r2;i++){
        temp[i][c2]=arr[i+1][c2];
    }
    
    for(int i=c2;i>c1;i--){
        temp[r2][i]=arr[r2][i-1];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]=temp[i][j];
        }
    }
}

void proc(){
    int temp[105][105];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            temp[i][j]=arr[i][j];
        }
    }

    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            int sum=arr[i][j];
            int num=1;
            for(int k=0;k<4;k++){
                int na=i+dr[k];
                int nb=j+dc[k];

                if(valid(na,nb)){
                    sum+=arr[na][nb];
                    num++;
                }
            }

            if(sum%num) sum=sum/num+1;
            else sum/=num;
            temp[i][j]=sum;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]=temp[i][j];
        }
    }
}

int main() {
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }


    for(int i=0;i<q;i++){
        cin>>r1>>c1>>r2>>c2;
        cycle();
        proc();

    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
