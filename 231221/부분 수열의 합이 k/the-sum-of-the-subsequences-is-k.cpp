#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k,x,ans=0;
    vector<int> v;
    vector<int> sum;
    cin>>n>>k;

    sum.push_back(0);


    for(int i=1;i<n;i++){
        cin>>x;
        sum.push_back(sum[i-1]+x);
    }

    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if((sum[j]-sum[i])==k){
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}