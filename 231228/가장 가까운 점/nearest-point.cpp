#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int n,m,r,x,y;
    priority_queue<tuple<int,int,int>> q;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        q.push({-(x+y),-x,-y});
    }

    for(int i=0;i<m;i++){
        tie(r,x,y)=q.top();
        q.pop();
        x=-x;
        y=-y;
        x+=2;
        y+=2;
        q.push({-(x+y),-x,-y});
    }

    tie(r,x,y)=q.top();
    cout<<-x<<' '<<-y;

    return 0;
}