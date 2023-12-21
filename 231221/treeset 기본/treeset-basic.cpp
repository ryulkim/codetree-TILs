#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, x;
    string s;
    set<int> st;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        
        if(s=="add"){
            cin>>x;
            st.insert(x);
        }
        else if(s=="remove"){
            cin>>x;
            st.erase(x);
        }
        else if(s=="find"){
            cin>>x;
            if(st.find(x)!=st.end()){
                cout<<"true\n";
            }
            else cout<<"false\n";
        }
        else if(s=="lower_bound"){
            cin>>x;
            if(st.lower_bound(x)!=st.end()) cout<<*st.lower_bound(x)<<'\n';
            else cout<<"None\n";
        }
        else if(s=="upper_bound"){
            cin>>x;
            if(st.upper_bound(x)!=st.end()) cout<<*st.upper_bound(x)<<'\n';
            else cout<<"None\n";
        }
        else if(s=="largest"){
            if(st.empty()) cout<<"None\n";
            else cout<<*st.rbegin()<<'\n';
        }
        else if(s=="smallest"){
            if(st.empty()) cout<<"None\n";
            else cout<<*st.begin()<<'\n';
        }
    }

    return 0;
}