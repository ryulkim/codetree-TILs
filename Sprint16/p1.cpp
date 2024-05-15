#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,x,ans=0;
vector<int> v;

int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int sz=v.size();

    for(int i=sz-1;i>=0;i--){
        int cnt=k/v[i];
        ans+=cnt;
        k-=cnt*v[i];
    }

    cout<<ans;

    return 0;
}
