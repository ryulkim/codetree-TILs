#include <iostream>
using namespace std;

int main() {
    int n,ans=0;
    string s;
    cin>>n>>s;
    
    for(int i=0;i<n;i++){
        if(s[i]!='C') continue;
        for(int j=i+1;j<n;j++){
            if(s[j]!='O') continue;
            for(int k=j+1;k<n;k++){
                if(s[k]!='W') continue;
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}