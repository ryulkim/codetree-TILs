#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n,x,y;
    int ans=0;
    set<int> s;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        auto it=s.upper_bound(y);
        if(it!=s.end()) {
            for(auto a=it;a!=s.end();a++) ans++;
            //cout<<*it<<" "<<y<<'\n';
            //cout<<ans<<'\n';

            s.erase(it, s.end());
        }
        if(y==0) continue;
        s.insert(y);
    }

    ans+=s.size();
    //cout<<s.size();

    cout<<ans;

    return 0;
}
