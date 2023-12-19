#include <iostream>
#include <set>
using namespace std;

int main() {
    int t, n, k;
    char c;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>k;
        set<int> s;

        for(int j=0;j<k;j++){
            cin>>c>>n;

            if(c=='I'){
                s.insert(n);
            }
            else if(c=='D'&&!s.empty()){
                if(n==1) s.erase(*s.rbegin());
                else s.erase(s.begin());
            }
        }

        if(s.empty()) cout<<"EMPTY\n";
        else cout<<*s.rbegin()<<" "<<*s.begin()<<'\n';
        
    }

    return 0;
}