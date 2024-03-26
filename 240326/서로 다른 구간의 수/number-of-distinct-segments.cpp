#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b,sum=0,ans=0;
vector<pair<int, int>> v;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }

    sort(v.begin(), v.end());

    for(int i=0;i<2*n;i++){
        if(v[i].second==1&&sum==0) {
            //cout<<v[i].first<<' ';
            ans++;
        }
        sum+=v[i].second;
    }

    cout<<ans;

    return 0;
}