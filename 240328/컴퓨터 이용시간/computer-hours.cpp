#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int n,p,q;
vector<tuple<int,int,int>> v;
priority_queue<int> pq;
int user[1000005];

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p>>q;
        v.push_back({p,1,i});
        v.push_back({q,-1,i});
        pq.push(-(i+1));
    }

    sort(v.begin(), v.end());

    int sum=0;
    int a,b,c;

    for(int i=0;i<2*n;i++){
        tie(a,b,c)=v[i];

        if(b==1){
            user[c]=-pq.top();
            pq.pop();
        }
        else{
            pq.push(-user[c]);
        }
    }

    for(int i=0;i<n;i++){
        cout<<user[i]<<' ';
    }

    return 0;
}