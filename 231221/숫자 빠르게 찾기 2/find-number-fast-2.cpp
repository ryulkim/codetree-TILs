#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m,x;
    set<int> s;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }

    for(int i=0;i<m;i++){
        cin>>x;
        if(s.lower_bound(x)!=s.end()) cout<<*s.lower_bound(x)<<'\n';
        else cout<<-1<<'\n';
    }

    return 0;
}