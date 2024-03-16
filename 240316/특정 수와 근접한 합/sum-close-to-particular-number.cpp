#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n,s,x, sum=0, ans=100000;
    vector<int> v;
    cin>>n>>s;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        sum+=x;
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int num=v[i]+v[j];
            ans=min(abs(s-(sum-num)),ans);
        }
    }

    cout<<ans;

    return 0;
}