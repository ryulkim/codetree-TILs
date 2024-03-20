#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

vector<int> v;
unordered_map<int,int> u;
priority_queue<pair<int, int>> q;

int main() {
    int n,k,x,a,b;
    
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        u[x]++;
    }

    int i=0;

    for(auto a: u){
    
        q.push({a.second, a.first});
        
    }

    //cout<<q.size()<<'\n';

    while(!q.empty()){
        if(i++==k) break;
        tie(a,b)=q.top();
        q.pop();
        cout<<b<<' ';
    }

    cout<<'\n';

    return 0;
}