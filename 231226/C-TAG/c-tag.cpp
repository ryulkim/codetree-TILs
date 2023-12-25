#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int n,m;
unordered_set<string> st;
vector<string> a;
vector<string> b;

bool sol(int j, int k, int l){
    st.clear();

    for(int i=0;i<n;i++){
        st.insert(to_string(a[i][j])+to_string(a[i][k])+to_string(a[i][l]));
    }

    for(int i=0;i<n;i++){
        if(st.find(to_string(b[i][j])+to_string(b[i][k])+to_string(b[i][l]))!=st.end()){
            return false;
        }
        //cout<<to_string(j)+to_string(k)+to_string(l)+to_string(i)<<'\n';
    }

    return true;
}

int main() {
    string s;
    int ans=0;

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>s;
        a.push_back(s);
    }

    for(int i=0;i<n;i++){
        cin>>s;
        b.push_back(s);
    }

    for(int j=0;j<m;j++){
        for(int k=j+1;k<m;k++){
            for(int l=k+1;l<m;l++){
                if(sol(j,k,l)){
                    ans++;
                }
            }
        }
    }

    
    

    cout<<ans;
    

    return 0;
}