#include <iostream>
using namespace std;

int sum[1002][1002][4];

int main() {
    int n,m,k,r1,c1,r2,c2;
    char x;
    
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            for(int l=0;l<3;l++){
                sum[i][j][l]+=sum[i][j-1][l];
            }
            sum[i][j][x-'a']+=1;
        }
    }

    for(int i=0;i<k;i++){
        int ans[4]={0,};
        cin>>r1>>c1>>r2>>c2;
        for(int j=r1;j<=r2;j++){
            for(int l=0;l<3;l++){
                ans[l]+=sum[j][c2][l]-sum[j][c1-1][l];
            }
        }
        for(int l=0;l<3;l++){
            cout<<ans[l]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}