#include <iostream>
#include <unordered_map>
using namespace std;

int n,x,y;
long long ans=0;
unordered_map<int, int> u;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(u.find(x)==u.end()) u[x]=y;
        else{
            if(u[x]>y) u[x]=y;
        }
    }

    for(auto pair: u){
        ans+=pair.second;
    }

    cout<<ans;

    return 0;
}