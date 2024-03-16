#include <iostream>
#include <stack>
using namespace std;

string s;
stack<bool> st;

bool proc(){
    int sz=s.size();
    
    for(int i=0;i<sz;i++){
        if(s[i]=='(') st.push(1);
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }

    if(st.empty()) return true;
    return false;
}

int main() {
    cin>>s;
    

    if(proc()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}