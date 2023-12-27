#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,m,x;
    priority_queue<int> pq;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }

    for(int i=0;i<m;i++){
        int a=pq.top();
        pq.pop();
        pq.push(a-1);
    }

    cout<<pq.top();

    return 0;
}