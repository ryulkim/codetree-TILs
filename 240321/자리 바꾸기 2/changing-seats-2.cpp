#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
using namespace std;

int n,k,a,b;
int arr[100005];
vector<pair<int, int>> v;
unordered_set<int> u[100005];

int main() {
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        arr[i]=i;
        u[i].insert(i);
    }

    for(int i=0;i<k;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<k;j++){
            tie(a,b)=v[j];
            //cout<<a<<' '<<b<<' '<<arr[a]<<' '<<arr[b]<<' ';
            int temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
            //cout<<arr[a]<<' '<<arr[b]<<'\n';
            u[arr[a]].insert(a);
            u[arr[b]].insert(b);
        }
    }

    for(int i=1;i<=n;i++){
        
        cout<<u[i].size()<<'\n';
    }

    return 0;
}