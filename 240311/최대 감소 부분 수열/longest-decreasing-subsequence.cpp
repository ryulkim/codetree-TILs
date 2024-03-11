#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,x, ans=0;
    vector<int> v;
    int arr[1005]={0,};
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]<v[j]){
                arr[i]=max(arr[i],arr[j]+1);
                ans=max(ans, arr[i]);
            }
        }
    }

    cout<<ans+1;

    return 0;
}