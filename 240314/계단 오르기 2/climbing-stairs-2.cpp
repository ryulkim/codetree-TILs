#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x, ans=0;
    vector<int> v;
    int dp[1005][1005]={0,};
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    dp[0][0]=0;
    dp[0][1]=v[0];
    dp[1][0]=v[1];
    dp[1][2]=v[0]+v[1];

    for(int i=0;i<n;i++){
        for(int j=0;j<=i+1;j++){
            if(dp[i][j]==0) continue;
            dp[i+2][j]=max(dp[i][j]+v[i+2],dp[i+2][j]);
            dp[i+1][j+1]=max(dp[i][j]+v[i+1],dp[i+1][j+1]);
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=3;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    ans=max(dp[n-1][0],dp[n-1][1]);
    ans=max(ans,dp[n-1][2]);
    ans=max(ans,dp[n-1][3]);

    cout<<ans;


    return 0;
}