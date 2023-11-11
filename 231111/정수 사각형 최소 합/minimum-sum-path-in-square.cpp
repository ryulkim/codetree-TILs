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

    dp[0][n-1]=g[0][n-1];

    for(int i=1;i<n;i++){
        dp[i][n-1]=g[i][n-1]+dp[i-1][n-1];
    }

    for(int i=n-2;i>=0;i--){
        dp[0][i]=g[0][i]+dp[0][i+1];
    }

    for(int i=1;i<n;i++){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=min(g[i][j]+dp[i][j+1], g[i][j]+dp[i-1][j]);
        }
    }

    cout<<dp[n-1][0]<<'\n';

    return 0;
}