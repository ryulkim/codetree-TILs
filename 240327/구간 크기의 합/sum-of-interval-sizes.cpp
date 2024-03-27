#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b;
vector<pair<int,int>> v;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }

    sort(v.begin(),v.end());

    int sum=0;
    int st=0;
    long long ans=0;

    for(int i=0;i<2*n;i++){
        sum+=v[i].second;
        if(sum==1&&v[i].second==1){
            st=v[i].first;
        }
        else if(sum==0&&v[i].second==-1){
            ans+=v[i].first-st;
        }
    }

    cout<<ans;

    return 0;
}