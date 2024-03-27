#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

multimap<int,int> st;
vector<tuple<int, int, int>> v;
int n,x1,x2,x,y,a,ans=0;


int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>y>>x1>>x2;
        v.push_back({x1,y,1});
        v.push_back({x2,y,-1});
    }

    sort(v.begin(), v.end());

    for(int i=0;i<2*n;i++){
        tie(x,y,a)=v[i];
        if(a==1){
            auto temp=*st.begin();
            int first=temp.first;
            st.insert({y,a});
            auto temp2=*st.begin();
            if(st.empty()||first!=temp2.first) {
                //cout<<x<<' ';
                ans++;
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