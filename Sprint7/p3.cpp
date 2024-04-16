#include <iostream>
#include <vector>
using namespace std;

int n,m,x,ans=0;
vector<int> v;

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    int st=0,en=0,sum=v[0];

    for(int i=0;i<n;i++){
        while(en+1<n&&sum+v[en+1]<=m){
            en++;
            sum+=v[en];
        }
        if(sum==m){
            ans++;
        }
        sum-=v[i];
    }

    cout<<ans;

    return 0;
}
