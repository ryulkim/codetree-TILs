#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,x,ans=-1;
unordered_map<int,int> u;
vector<int> v;

int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=n-1;i>=0;i--){
        if(u.find(v[i])==u.end()){
            u[v[i]]=i;
        }
        else{
            if(u[v[i]]-i<=k) ans=max(ans, v[i]);
            u[v[i]]=i;
        }
    }

    cout<<ans;

    return 0;
}