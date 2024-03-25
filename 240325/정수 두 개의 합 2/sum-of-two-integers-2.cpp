#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,x,ans=0;
vector<int> v;

void proc(){
    
    for(int i=0;i<n-1;i++){
        int a=v[i];
        int j=i;
        while(j+1<n&&a+v[j+1]<=k){
            ans++;
            j++;
        }
    }
}

int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    proc();

    cout<<ans;


    return 0;
}