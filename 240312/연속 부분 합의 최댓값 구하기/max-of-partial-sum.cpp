#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x;
    vector<int> v;
    int dp[10004]={0,};
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    dp[0]=v[0];
    int ans=v[0];

    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+v[i],v[i]);
        ans=max(ans,dp[i]);
    }

    cout<<ans;
    
    return 0;
}