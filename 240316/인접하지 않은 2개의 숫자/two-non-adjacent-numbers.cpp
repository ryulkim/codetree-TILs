#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x,ans=0;
    vector<int> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n-2;i++){
        for(int j=i+2;j<n;j++){
            ans=max(ans,v[i]+v[j]);
        }
    }

    cout<<ans;
    return 0;
}