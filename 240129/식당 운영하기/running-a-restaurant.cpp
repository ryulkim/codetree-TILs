#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int d,p,n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int,int>> v;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p>>d;
        v.push_back({d,p});
    }

    sort(v.begin(), v.end());
    int ans=0;

    for(int i=0;i<n;i++){
        pq.push(v[i].second);
        ans+=v[i].second;
        
        if(pq.size()>v[i].first){
            ans-=pq.top();
            pq.pop();
        }

        //cout<<ans<<' ';
    }

    cout<<ans;

    return 0;
}