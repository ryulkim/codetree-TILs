#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m,x;
    set<int> s;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        s.insert(i);
    }

    for(int i=0;i<n;i++){
        cin>>x;
        s.erase(x);
        cout<<*s.rbegin()<<'\n';
    }

    return 0;
}