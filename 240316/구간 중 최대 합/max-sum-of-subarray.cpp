#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,k,x,ans=0;
    vector<int> v;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n-k;i++){
        int num=0;
        for(int j=i;j<i+k;j++){
            num+=v[j];
        }
        ans=max(ans,num);
    }

    cout<<ans;
    return 0;
}