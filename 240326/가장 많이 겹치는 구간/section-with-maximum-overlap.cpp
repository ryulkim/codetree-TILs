#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,x1,x2,ans=0,sum=0;
vector<pair<int, int>> v;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x1>>x2;
        v.push_back({x1,1});
        v.push_back({x2,-1});
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        sum+=v[i].second;
        ans=max(ans,sum);
    }

    cout<<ans;

    return 0;
}