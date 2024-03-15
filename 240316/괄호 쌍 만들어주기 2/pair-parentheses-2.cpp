#include <iostream>
using namespace std;

int main() {
    string s;
    int ans=0;
    cin>>s;
    int sz=s.size();

    for(int i=1;i<sz-2;i++){
        if(s[i]!='('||s[i-1]!='(') continue;
        for(int j=i+2;j<sz;j++){
            if(s[j]==')'&&s[j-1]==')'){
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}