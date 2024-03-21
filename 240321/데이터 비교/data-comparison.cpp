#include <iostream>
#include <unordered_set>
using namespace std;

int n,m,x;
unordered_set<int> u;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        u.insert(x);
    }

    cin>>m;

    for(int i=0;i<m;i++){
        cin>>x;
        if(u.find(x)!=u.end()){
            cout<<1<<' ';
        }
        else{
            cout<<0<<' ';
        }
    }
    return 0;
}