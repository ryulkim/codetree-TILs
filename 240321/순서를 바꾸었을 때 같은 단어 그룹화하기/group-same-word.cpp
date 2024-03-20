#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
string s;
unordered_map<char, int> u[1005];
int group[1005];
int cnt[1005];

int main() {
    cin>>n;


    for(int i=0;i<n;i++){
        cin>>s;
        int sz=s.size();
        for(int j=0;j<sz;j++){
            u[i][s[j]]++;
        }
    }

    int a=1;

    for(int i=0;i<n;i++){
        if(group[i]==0) {
            group[i]=a++;
            cnt[group[i]]++;
        }
        for(int j=i+1;j<n;j++){
            if(group[j]!=0) continue;
            bool chk=true;
            for(int k=0;k<26;k++){
                if(u[i]['a'+k]!=u[j]['a'+k]) {
                    chk=false;
                    break;
                }
            }
            if(chk==true) {
                group[j]=group[i];
                cnt[group[j]]++;
            }

        }
    }

    sort(cnt, cnt+1000, greater<int>());


    cout<<cnt[0];


    return 0;
}