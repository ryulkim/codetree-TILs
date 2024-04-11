#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,a,b;
long long ans=1e9;
vector<int> v;

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int end=n-1;
    for(int i=0;i<end;i++){
        if(ans>abs(v[i]+v[end])){
            ans=abs(v[i]+v[end]);
            a=v[i];
            b=v[end];
            //cout<<a<<' '<<b<<'\n';
        }
        while(1){
            if(abs(v[i])>abs(v[end])) break;
            if(ans>abs(v[i]+v[end])){
                ans=abs(v[i]+v[end]);
                a=v[i];
                b=v[end];
            }
            end--;

        }
        
    }

    cout<<a<<' '<<b;

    return 0;
}