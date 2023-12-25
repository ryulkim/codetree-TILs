#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m,x,y;
    set<pair<int,int>> s;
    set<pair<int,int>>::iterator iter;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        s.insert({x,y});
    }

    for(int i=0;i<m;i++){
        cin>>x>>y;
        iter=s.lower_bound({x,y});
        if(iter!=s.end()){
            cout<<(*iter).first<<' '<<(*iter).second<<'\n';
        }
        else{
            cout<<-1<<' '<<-1<<'\n';
        }
    }

    return 0;
}