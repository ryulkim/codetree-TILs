#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n,q,x,a,b;
vector<int> v;
map<int,int> m;


int main() {
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        m[v[i]]=i;
    }

    for(int i=0;i<q;i++){
        cin>>a>>b;
        auto right=m.upper_bound(b);
        auto left=m.lower_bound(a);
        if(right==m.end()){
            cout<<n-(*left).second<<'\n';
        }
        else{
            cout<<(*right).second-(*left).second<<'\n';
        }
        


    }

    return 0;
}