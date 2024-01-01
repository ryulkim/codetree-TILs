#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
using namespace std;

int main() {
    int n,k,a,b;
    vector<int> v;
    vector<pair<int, int>> c;
    unordered_set<int> u[100003];
    cin>>n>>k;

    v.push_back(0);

    for(int i=1;i<=n;i++){
        v.push_back(i);
        u[i].insert(i);
    }

    for(int i=0;i<k;i++){
        cin>>a>>b;
        c.push_back({a,b});
    }

    for(int i=0;i<3;i++){
        for(int i=0;i<k;i++){
            tie(a,b)=c[i];
            int temp;
            temp=v[a];
            v[a]=v[b];
            v[b]=temp;
            
            u[v[a]].insert(a);
            u[v[b]].insert(b);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<u[i].size()<<'\n';
    }

    return 0;
}