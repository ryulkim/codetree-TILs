#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,x,ans=0;
vector<int> v;

void proc(){

    int j=n-1;
    
    for(int i=0;i<n-1;i++){
        int a=v[i];
        
        while(j>i&&a+v[j]>k){
            j--;
        }

        if(j>i) {
            //cout<<j<<'-'<<i<<' ';
            ans+=j-i;
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