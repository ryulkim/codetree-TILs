#include <iostream>
using namespace std;

int dp[1005];

int main() {
    int n;
    cin>>n;
    
    dp[0]=1;
    

    for(int i=0;i<=n-2;i++){
        dp[i+2]=(dp[i+2]+dp[i])%10007;
        dp[i+3]=(dp[i+3]+dp[i])%10007;
    }

    cout<<dp[n];

    return 0;
}