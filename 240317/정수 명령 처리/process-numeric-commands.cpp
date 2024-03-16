#include <iostream>
#include <stack>
using namespace std;

int n,x;
string s;
stack<int> st;

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="push"){
            cin>>x;
            st.push(x);
        }
        else if(s=="size"){
            cout<<st.size()<<'\n';
        }
        else if(s=="pop"){
            cout<<st.top()<<'\n';
            st.pop();
        }
        else if(s=="top"){
            cout<<st.top()<<'\n';
        }
        else if(s=="empty"){
            cout<<st.empty()<<'\n';
        }
    }
    return 0;
}