#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    priority_queue<int> pq;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0&&pq.empty()){
            cout<<0<<'\n';
        }
        else if(x==0){
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        else{
            pq.push(x);
        }
    }


    return 0;
}