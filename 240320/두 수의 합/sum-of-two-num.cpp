#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n,k,x,ans=0;
    unordered_map<int,int> u;
    vector<int> v;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        u[x]++;
    }

    for(int i=0;i<n;i++){
        if(k-v[i]==v[i]) {
            ans+=u[k-v[i]]---1;
        }
        else{
            u[v[i]]--;
            ans+=u[k-v[i]]--;
        }
        
        
    }

    cout<<ans;

    return 0;
}