#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};

int main() {
    int n,m;
    vector<string> v;
    unordered_set<pair<string, string>,pair_hash> st;
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