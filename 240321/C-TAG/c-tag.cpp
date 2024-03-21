#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> a,b;
string s;
int n,m, ans=0;


int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>s;
        a.push_back(s);
    }

    for(int i=0;i<n;i++){
        cin>>s;
        b.push_back(s);
    }
    
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                bool chk=true;
                unordered_set<string> u;
                for(int l=0;l<n;l++){
                    string s=to_string(a[l][i])+to_string(a[l][j])+to_string(a[l][k]);
                    u.insert(s);
                }
                for(int l=0;l<n;l++){
                    string s=to_string(b[l][i])+to_string(b[l][j])+to_string(b[l][k]);
                    if(u.find(s)!=u.end()){
                        chk=false;
                        break;
                    }
                }
                if(chk==true) ans++;
                else continue;
            }
        }
    }
    
    cout<<ans;
    

    return 0;
}