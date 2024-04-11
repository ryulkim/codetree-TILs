#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int indegree[10];
vector<int> v[10];
int n;
string a,b,c,d,e,f;
unordered_map<int, string> intToString;
unordered_map<string, int> stringtoInt;
queue<int> q;


int main() {
    stringtoInt["Beatrice"]=0;
    intToString[0]="Beatrice";
    stringtoInt["Belinda"]=1;
    intToString[1]="Belinda";
    stringtoInt["Bella"]=2;
    intToString[2]="Bella";
    stringtoInt["Bessie"]=3;
    intToString[3]="Bessie";
    stringtoInt["Betsy"]=4;
    intToString[4]="Betsy";
    stringtoInt["Blue"]=5;
    intToString[5]="Blue";
    stringtoInt["Buttercup"]=6;
    intToString[6]="Buttercup";
    stringtoInt["Sue"]=7;
    intToString[7]="Sue";

    // for(int i=0;i<7;i++){
    //     for(int j=i+1;j<8;j++){
    //         v[i].push_back(j);
    //     }
    // }

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d>>e>>f;

        int ai=stringtoInt[a];
        int fi=stringtoInt[f];

        v[ai].push_back(fi);
        v[fi].push_back(ai);

        indegree[ai]++;
        indegree[fi]++;
    }

    // for(int i=0;i<8;i++){
    //     cout<<indegree[i]<<' ';
    // }
    // cout<<'\n';

    for(int i=0;i<8;i++){
        if(indegree[i]>1||indegree[i]<0) continue;
        
        q.push(i);
        //cout<<"a: "<<i<<'\n';

        while(!q.empty()){
            int a=q.front();
            indegree[a]=-1;
            q.pop();
            int sz=v[a].size();
            cout<<intToString[a]<<'\n';

            sort(v[a].begin(),v[a].end());

            for(int j=0;j<sz;j++){
                //cout<<v[a][j]<<'\n';
                indegree[v[a][j]]--;
                if(indegree[v[a][j]]<2&&indegree[v[a][j]]>=0) q.push(v[a][j]);
            }
        }

        
    }


    return 0;
}