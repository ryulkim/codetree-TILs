#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin>>a>>b;
    int al=a.size();
    int bl=b.size();
    int dp[1002][1002]={0,};

    a[0]==b[0]?dp[0][0]=1:dp[0][0]=0;

    for(int i=1;i<al;i++){
        if(a[0]==b[i]){
            dp[0][i]=1;
        }
        else{
            dp[0][i]=dp[0][i-1];
        }
    }

    for(int i=1;i<bl;i++){
        if(a[i]==b[0]) dp[i][0]=1;
        else dp[i][0]=dp[i-1][0];
    }

    for(int i=1;i<al;i++){
        for(int j=1;j<bl;j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<<dp[al-1][bl-1];

    return 0;
}