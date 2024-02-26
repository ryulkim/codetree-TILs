#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x,ans=-1e9;
    vector<int> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(i==0) v.push_back(x);
        else{
            v.push_back(max(v[i-1],0)+x);
        }
        ans=max(ans,v[i]);
    }

    cout<<ans;

    return 0;
}
