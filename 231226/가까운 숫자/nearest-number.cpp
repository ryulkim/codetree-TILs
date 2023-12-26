#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, x, ans=1e9;
    set<int> s;
    set<int>::iterator iter;
    cin>>n;

    s.insert(0);

    for(int i=0;i<n;i++){
        cin>>x;
        iter=s.upper_bound(x);

        if(iter!=s.end()){
            ans=min(ans,*iter-x);
        }
        
        ans=min(ans,x-*(--iter));

        cout<<ans<<'\n';

        s.insert(x);
        
    }

    

    return 0;
}