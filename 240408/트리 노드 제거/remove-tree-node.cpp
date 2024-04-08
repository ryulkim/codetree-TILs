#include <iostream>
#include <unordered_set>
#define SZ 55
using namespace std;

int n,x,ans=0;
int par[SZ];
int leaf[SZ];
unordered_set<int> st;

int main() {
    cin>>n;

    for(int i=0;i<n-1;i++){
        cin>>par[i];
        st.insert(i);
        leaf[par[i]]++;
    }

    cin>>x;
    st.erase(x);

    for(int i=0;i<n;i++){
        if(par[i]==x) par[i]==-1;
        if(par[i]!=-1&&st.find(par[i])==st.end()){
            ans++;
        }
    }

    cout<<ans;

    return 0;
}