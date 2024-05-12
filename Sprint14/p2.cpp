#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n,x;
unordered_map<int, int> u;
vector<int> v;
int arr[100005];

int main() {
    cin>>n;

    fill(arr, arr+100000, -1);

    for(int i=0;i<n;i++){
        cin>>x;
        if(u.find(x)!=u.end()){
            v.push_back(u[x]);
        }
        else{
            v.push_back(-1);
        }
        u[x]=i;
    }


    int f=0;
    int ans=1;
    for(int i=1;i<n;i++){
        if(v[i]!=-1&&f<v[i]){
            f=v[i];
        }
        ans=max(ans,i-f);
    }

    cout<<ans;

    return 0;
}
