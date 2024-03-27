#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

multimap<int,int> st;
unordered_set<int> cnt;
vector<tuple<int, int, int,int>> v;
int n,x1,x2,x,y,a,idx,ans=0;


int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>y>>x1>>x2;
        v.push_back({x1,y,i,1});
        v.push_back({x2,y,i,-1});
    }

    sort(v.begin(), v.end());

    for(int i=0;i<2*n;i++){
        tie(x,y,idx,a)=v[i];
        if(a==1){
            auto temp=*st.begin();
            int first=temp.first;
            st.insert({y,a});
            auto temp2=*st.begin();
            if(st.empty()||first!=temp2.first) {
                //cout<<x<<' ';
                if(cnt.find(idx)==cnt.end()) {
                    cnt.insert(idx);
                    ans++;
                }
            }
        }
        else{
            auto temp=*st.begin();
            int first=temp.first;
            int second=temp.second;
            auto it=st.find(y);

            st.erase(it);
            auto temp2=*st.begin();
            if(!st.empty()&&first!=temp2.first||first==temp2.first&&y==temp2.first) {
                //cout<<x<<' ';
                ans++;
            }
        }
    }

    cout<<ans;


    return 0;
}