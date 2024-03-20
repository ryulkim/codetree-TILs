#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n,k,x, ans=0;
    vector<int> v;
    
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++){
        int t=k-v[i];
        unordered_map<int, int> u;
        for(int j=0;j<i;j++){
            ans+=u[t-v[j]];
            u[v[j]]++;
        }
    }

    cout<<ans;
    return 0;
}