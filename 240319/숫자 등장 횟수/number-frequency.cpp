#include <iostream>
#include <unordered_map>
using namespace std;

int n,m,x;
unordered_map<int, int> u;

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        u[x]++;
    }

    for(int i=0;i<m;i++){
        cin>>x;
        cout<<u[x]<<' ';
    }
    return 0;
}