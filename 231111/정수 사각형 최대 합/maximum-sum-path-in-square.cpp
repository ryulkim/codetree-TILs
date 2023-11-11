#include <iostream>
using namespace std;

int main() {
    int n;
    int dp[103][103]={0,};
    int g[103][103]={0,};
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    
    dp[0][0]=g[0][0];

    for(int i=1;i<n;i++){
        dp[i][0]=g[i][0]+dp[i-1][0];
    }

    for(int i=1;i<n;i++){
        dp[0][i]=g[0][i]+dp[0][i-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j]+g[i][j], dp[i][j-1]+g[i][j]);
        }
    }

    int m=0;


    for(int i=0;i<n;i++){
        m=max(m,dp[n-1][i]);
    }

    cout<<m<<'\n';

    return 0;
}