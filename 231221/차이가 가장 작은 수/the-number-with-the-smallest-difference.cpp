#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m,x;
    set<int> s;
    vector<int> v;
    int ans=2e9;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        s.insert(x);
    }

    int sz=v.size();

    for(int i=0;i<sz;i++){
        //a-b>=m -> b<=a-m
        set<int>::iterator iter;
        iter=s.upper_bound(v[i]-m);
        if(iter!=s.begin()){
            iter--;
            ans=min(ans, v[i]-*iter);
        }

        //b-a>=m -> b>=m+a
        iter=s.lower_bound(m+v[i]);
        if(iter!=s.end()){
            ans=min(ans, *iter-v[i]);
        }
    }

    if(ans==2e9){
        cout<<-1;
    }
    else cout<<ans;

    return 0;
}