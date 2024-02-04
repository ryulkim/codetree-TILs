#include <iostream>
using namespace std;

bool check[202][202];

int main() {
    int n,m,a,b, ans=0;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        check[a][b]=1;
        check[b][a]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(check[i][j]) continue;

            for(int k=j+1;k<=n;k++){
                if(check[i][k]||check[j][k]) continue;
                //cout<<i<<" "<<j<<" "<<k<<'\n';
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}
