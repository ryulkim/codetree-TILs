#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
    int n,m;
    vector<string> v;
    set<pair<string, string>> st;
    string s;

    cin>>n>>m;

    for(int i=0;i<2*n;i++){
        cin>>s;
        v.push_back(s);
    }

    for(int j=0;j<m;j++){
        for(int k=j+1;k<m;k++){
            for(int l=k+1;l<m;l++){
                for(int i=0;i<n;i++){
                    //cout<<to_string(v[i][j])+to_string(v[i][k])<<'\n';
                    st.insert({to_string(j)+to_string(k)+to_string(l),to_string(v[i][j])+to_string(v[i][k])+to_string(v[i][l])});
                }
            }
        }
    }

    int ans=0;
    
    for(int j=0;j<m;j++){
        for(int k=j+1;k<m;k++){
            for(int l=k+1;l<m;l++){
                for(int i=n;i<2*n;i++){
                    //cout<<v[i][j]<<'\n';
                    if(st.find({to_string(j)+to_string(k)+to_string(l),to_string(v[i][j])+to_string(v[i][k])+to_string(v[i][l])})!=st.end()){
                        break;
                    }
                    //cout<<to_string(j)+to_string(k)+to_string(l)<<'\n';
                    if(i==2*n-1) ans++;
                }
            }
        }
    }

    cout<<ans;
    

    return 0;
}