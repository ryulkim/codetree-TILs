#include <iostream>
#include <vector>
using namespace std;

long long arr[100005];
string s;
long long ans=0;

int main() {
    
    cin>>s;

    int sz=s.size();

    for(int i=sz-2;i>=0;i--){
        if(s[i]==')'&&s[i+1]==')'){
            arr[i]=arr[i+1]+1;
            //cout<<i<<' '<<arr[i]<<'\n';
        }
        else{
            arr[i]=arr[i+1];
        }
    }
    //cout<<'\n';

    // for(int i=0;i<sz-1;i++){
    //     cout<<arr[i]<<' ';
    // }

    for(int i=0;i<sz-1;i++){
        if(s[i]=='('&&s[i+1]=='('){
            ans+=arr[i];
        }
    }

    cout<<ans;

    return 0;
}