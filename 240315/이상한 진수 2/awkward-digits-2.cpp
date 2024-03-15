#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string a;
    bool zero=0;
    
    cin>>a;

    int sz=a.size();

    for(int i=0;i<sz;i++){
        if(a[i]=='0'){
            zero=1;
            a[i]='1';
            break;
        }
    }

    if(zero==0){
        a[sz-1]='0';
    }

    int ans=0;

    for(int i=0;i<=sz;i++){
        if(a[i]=='1'){
            ans+=pow(2,sz-1-i);
        }
    }

    cout<<ans;

    return 0;
}