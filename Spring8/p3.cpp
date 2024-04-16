#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans=0;
int arr[30][30];
int dp[30][30];

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    if(arr[0][0]<=0) dp[0][0]=1;

    for(int i=1;i<n;i++){
        if(arr[i][0]<=0) dp[i][0]+=(dp[i-1][0]+1);
        else dp[i][0]+=dp[i-1][0];
    }

    for(int i=1;i<m;i++){
        if(arr[0][i]<=0) dp[0][i]+=(dp[0][i-1]+1);
        else dp[0][i]+=dp[0][i-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]<=0) dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=0;k<m;k++){
                for(int l=k;l<m;l++){
                    if(i==0&&k==0){
                        if(!dp[j][l]){
                            ans=max(ans,(j-i+1)*(l-k+1));
                        }
                    }
                    else if(i==0){
                        if(!(dp[j][l]-dp[j][k-1])){
                            ans=max(ans,(j-i+1)*(l-k+1));
                        }
                    }
                    else if(k==0){
                        if(!(dp[j][l]-dp[i-1][l])){
                            ans=max(ans,(j-i+1)*(l-k+1));
                        }
                    }
                    else{
                        if(!(dp[j][l]-dp[i-1][l]-dp[j][k-1]+dp[i-1][k-1])){
                            ans=max(ans,(j-i+1)*(l-k+1));
                        }
                    }
                }
            }
        }
    }

    if(ans==0) cout<<-1;
    else cout<<ans;

    return 0;
}
