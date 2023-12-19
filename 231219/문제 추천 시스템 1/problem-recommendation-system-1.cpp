#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int main() {
    int n,p,l,m,x;
    string c;
    set<pair<int,int>> s;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p>>l;
        s.insert({l,p});
    }

    cin>>m;

    for(int i=0;i<m;i++){
        cin>>c;
        if(c=="ad"){
            cin>>p>>l;
            s.insert({l,p});
        }
        else if(c=="rc"){
            cin>>x;
            if(x==1){
                tie(l, p)=*s.rbegin();
                cout<<p<<'\n';
            }
            else{
                tie(l, p)=*s.begin();
                cout<<p<<'\n';
            }
        }
        else if(c=="sv"){
            cin>>p>>l;
            s.erase({l,p});
        }
    }
    
    return 0;
}