#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
long long x;
long long ans=1e10;
vector<long long> v;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int end=n-1;

    for(int i=0;i<end;i++){
        while(1){
            ans=min(ans,abs(v[i]+v[end]));
            if(end-1>i&&abs(v[i])<abs(v[end])) end--;
            else break;
        }
    }

    cout<<ans;

    return 0;
}