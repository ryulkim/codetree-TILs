#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x,ans=0;
    vector<int> player1, player2;
    int dp[2005][2005]={0,}; //player1의 i번째 카드와 player2의 j번째 카드 대결일 때, p2가 얻는 최대로 얻는 점수

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        player1.push_back(x);
    }

    for(int i=0;i<n;i++){
        cin>>x;
        player2.push_back(x);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //p1의 카드가 더 작을 때
            if(player1[i]<player2[j]){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            }
            //p2의 카드가 더 작을 때
            if(player1[i]>player2[j]){
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]+player2[j]);
            }
            //카드를 버리는 경우
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][n]);
    }

    cout<<ans;
    

    return 0;
}