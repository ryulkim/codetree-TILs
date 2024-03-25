#include <iostream>
#include <vector>
using namespace std;

int n,m,x,ans=0;
vector<int> v;

void proc(){
    int j=0;
    int sum=v[j];

    for(int i=0;i<n;i++){
        while(j+1<n&&v[j+1]+sum<=m){
            j++;
            sum+=v[j];
        }

        if(sum==m) ans++;
        sum-=v[i];
    }
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    
    proc();

    cout<<ans;
    return 0;
}