#include <iostream>
#include <unordered_map>
#include <vector>
#define SZ_N 50002
#define SZ_M 7
using namespace std;

int main() {
    int n,m,k,x;
    unordered_map<int,int> u[SZ_M][30]; //자리수, 알파벳, key(점수), value(학생 수)
    vector<pair<string, int>> v;
    int ans[SZ_N]={0,};
    string s;
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        cin>>s>>x;
        v.push_back({s,x});

        for(int j=0;j<m;j++){
            u[j][s[j]-'a'][x]++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            string s=v[i].first;
            int x=v[i].second;
            ans[i]+=u[j][s[j]-'a'][k-x];

            if(k==x*2) ans[i]--;
        }

        cout<<ans[i]<<'\n';
    }

    return 0;
}
