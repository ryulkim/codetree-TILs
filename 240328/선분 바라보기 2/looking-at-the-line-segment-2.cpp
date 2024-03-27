#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

set<int> st;
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
            int first=*st.begin();
            st.insert(y);
            if(!st.empty()&&first!=*st.begin()) {
                //cout<<x<<' ';
                ans++;
            }
        }
        else{
            int first=*st.begin();
            st.erase(y);
            if(!st.empty()&&first!=*st.begin()) {
                //cout<<x<<' ';
                ans++;
            }
        }
    }

    cout<<ans;


    return 0;
}