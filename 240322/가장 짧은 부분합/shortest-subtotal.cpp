#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,s,x;
vector<int> v;

int main() {
    cin>>n>>s;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    int j=-1,sum=0,len=0,ans=1e9;

    for(int i=0;i<n;i++){
        while(j+1<n&&v[j+1]+sum<=s){
            sum+=v[j];
            len++;
            j++;
        }

        ans=min(ans, len);
        sum-=v[i];
        len--;
    }

    cout<<ans;
    
    return 0;
}