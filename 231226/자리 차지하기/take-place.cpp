#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m,x, ans=0;
    set<int> s;
    set<int>::iterator iter;

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        s.insert(i);
    }

    for(int i=0;i<n;i++){
        cin>>x;
        iter=s.upper_bound(x);

        if(iter!=s.begin()){
            s.erase(--iter);
            ans++;
        }

        
    }

    cout<<ans;


    return 0;
}