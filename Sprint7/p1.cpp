#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
bool arr[305][305];
int dp[305][305];

bool valid(int i, int j){
    return i>=0&&i<n&&j>=0&&j<m;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0]=arr[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(valid(i+1,j)){
                dp[i+1][j]=max(dp[i+1][j],arr[i+1][j]+dp[i][j]);
            }
            if(valid(i,j+1)){
                dp[i][j+1]=max(dp[i][j+1],arr[i][j+1]+dp[i][j]);
            }
        }
    }

    cout<<dp[n-1][m-1];

    return 0;
}
