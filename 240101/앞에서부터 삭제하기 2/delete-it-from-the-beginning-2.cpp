#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n,k,x;
    vector<int> v;
    double ans=0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int k=1;k<=n-2;k++){
        double value=0;
        priority_queue<int> pq;
        for(int i=k;i<n;i++){
            pq.push(-v[i]);
            value+=v[i];
        }

        value-=-pq.top();
        value/=n-k-1;
        ans=max(ans,value);
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ans;
    
    return 0;
}