#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n,m;
    string s;
    unordered_map<string, string> a;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>s;
        a[s]=to_string(i);
        a[to_string(i)]=s;
    }

    for(int i=0;i<m;i++){
        cin>>s;
        cout<<a[s]<<'\n';
    }

    return 0;
}