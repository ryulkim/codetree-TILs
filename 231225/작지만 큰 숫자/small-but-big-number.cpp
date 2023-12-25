#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m,x;
    set<int> s;
    set<int>::iterator iter;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(-x);
    }

    for(int i=0;i<m;i++){
        cin>>x;
        iter=s.lower_bound(-x);
        if(iter!=s.end()){
            cout<<-*iter<<'\n';
            s.erase(iter);
        }
        else{
            cout<<-1<<'\n';
        }
    }
    
    return 0;
}