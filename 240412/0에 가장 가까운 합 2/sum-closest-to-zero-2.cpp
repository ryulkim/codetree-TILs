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
        while(1){
            if(ans>abs(v[i]+v[end])){
                ans=abs(v[i]+v[end]);
                a=v[i];
                b=v[end];
            }
            if(end-1>i&&abs(v[i])<abs(v[end])) end--;
            else break;

        }
        
    }

    cout<<a<<' '<<b;

    return 0;
}