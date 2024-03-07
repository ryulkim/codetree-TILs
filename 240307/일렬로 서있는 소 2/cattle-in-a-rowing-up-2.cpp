#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,x,ans=0;
    vector<int> v;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(v[i]<=v[j]&&v[j]<=v[k]){
                    ans++;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}