#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int n,k,x,a,b;
    vector<int> v;
    unordered_map<int,int> u;
    priority_queue<pair<int, int>> q;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        u[x]++;
    }

    for(auto a: u){
        if(a.second>=k){
            q.push({a.second, a.first});
        }   
    }

    while(!q.empty()){
        tie(a,b)=q.top();
        q.pop();
        cout<<b<<' ';
    }

    cout<<'\n';

    return 0;
}