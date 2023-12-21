#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int n, x;
    string s;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="push"){
            cin>>x;
            pq.push(x);
        }
        else if(s=="size") cout<<pq.size()<<'\n';
        else if(s=="empty"){
            if(pq.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(s=="pop"){
            cout<<pq.top()<<'\n';
            pq.pop();

        } 
        else if(s=="top"){
            cout<<pq.top()<<'\n';
        }
    }
    return 0;
}