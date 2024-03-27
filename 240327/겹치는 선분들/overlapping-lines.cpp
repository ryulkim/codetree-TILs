#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,x,sum=0;
char c;
int pos=0;
vector<pair<long long, int>> v;


int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x>>c;
        if(c=='R'){
            v.push_back({pos,1});
            v.push_back({pos+x,-1});
            pos+=x;
        }
        else{
            v.push_back({pos,-1});
            v.push_back({pos-x,1});
            pos-=x;
        }
    }

    sort(v.begin(), v.end());
    int st=0;
    int fi=0;
    long long ans=0;

    for(int i=0;i<2*n;i++){
        //cout<<v[i].first<<' ';
        sum+=v[i].second;
        if(sum==k&&v[i].second==1){
            st=v[i].first;
        }
        else if(sum==k-1&&v[i].second==-1){
            ans+=v[i].first-st;
            //cout<<v[i].first<<' '<<st<<'\n';
        }
    }

    cout<<ans;

    return 0;
}