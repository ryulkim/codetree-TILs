#include <iostream>
using namespace std;

int main() {
    string s;
    int ans=0;
    cin>>s;
    int sz=s.size();

    for(int i=0;i<sz;i++){
        if(s[i]==')') continue;
        for(int j=i+1;j<sz;j++){
            if(s[j]==')'){
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}