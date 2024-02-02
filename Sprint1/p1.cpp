#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m,x,ans=-1;
    vector<int> v;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                int value=v[i]+v[j]+v[k];

                if(value<=m) ans=max(ans,v[i]+v[j]+v[k]);
            }
        }
    }

    cout<<ans;

    return 0;
}
