#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n,k,x;
    vector<int> v;
    priority_queue<int> pq;
    double ans=0;
    int sum=0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sum+=v[n-1];
    pq.push(-v[n-1]);

    for(int k=n-2;k>=1;k--){
        
        pq.push(-v[k]);
        sum+=v[k];
        ans=max(ans,(double)(sum+pq.top())/(n-k-1));
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ans;
    
    return 0;
}