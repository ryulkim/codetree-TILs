#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n,q,x,a,b;
    vector<int> v;
    set<int> s;
    //auto lit;
    //auto rit;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        s.insert(x);
    }

    for(int i=0;i<q;i++){
        cin>>a>>b;
        auto lit=s.lower_bound(a);
        auto rit=s.upper_bound(b);
        int ans=0;
        for(;lit!=rit;lit++){
            ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}