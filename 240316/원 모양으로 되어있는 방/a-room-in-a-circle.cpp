#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x,ans=1e9;
    vector<int> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++){
        int num=0;
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j]*num++;
        }
        for(int j=0;j<i;j++){
            sum+=v[j]*num++;
        }
        ans=min(ans,sum);
    }

    cout<<ans;

    return 0;
}