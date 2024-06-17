#include <iostream>
#include <deque>

using namespace std;

deque<int> q;

int main() {
    int n,t,x;

    cin>>n>>t;

    for(int c=0;c<3;c++){
        for(int i=0;i<n;i++){
            cin>>x;
            q.push_back(x);
        }
    }

    for(int i=0;i<t;i++){
        x=q.back();
        q.pop_back();
        q.push_front(x);
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cout<<q.front()<<' ';
            q.pop_front();
        }
        cout<<'\n';
    }

    

    return 0;
}