#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n,x;
string s;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="push"){
            cin>>x;
            q.push(x);
        }
        else if(s=="pop"){
            cout<<q.front()<<'\n';
            q.pop();
        }
        else if(s=="size"){
            cout<<q.size()<<'\n';
        }
        else if(s=="empty"){
            cout<<q.empty()<<'\n';
        }
        else if(s=="front"){
            cout<<q.front()<<'\n';
        }
    }
    return 0;
}