#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n,x,y,ans=1e9;
    vector<pair<int,int>> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }

    for(int i=1;i<n-1;i++){
        int sum=0;
        for(int j=0;j<n-1;j++){
            if(j==i) continue;
            int ax=v[j].first;
            int ay=v[j].second;
            int nx=j+1;
            if(nx==i) nx+=1;
            int bx=v[nx].first;
            int by=v[nx].second;

            sum+=abs(ax-bx)+abs(ay-by);
        }
        ans=min(ans,sum);
    }

    cout<<ans;
    
    return 0;
}