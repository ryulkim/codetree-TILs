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

        if(a<f){
            if(v[ai].size()==0){
                v[ai].push_back(fi);
                indegree[fi]++;
            }
            else if(v[ai].size()>0&&fi<v[ai][0]) {
                v[fi].push_back(ai);
                indegree[ai]++;
            }
            else{
                v[v[ai][0]].push_back(ai);
                indegree[v[ai][0]]--;
                v[ai][0]=fi;
                indegree[fi]++;
                indegree[ai]++;
            }
            
        }
        else{
            if(v[fi].size()==0){
                v[fi].push_back(ai);
                indegree[ai]++;
            }
            else if(v[fi].size()>0&&ai<v[fi][0]) {
                v[ai].push_back(fi);
                indegree[fi]++;
            }
            else{
                v[v[fi][0]].push_back(fi);
                indegree[v[fi][0]]--;
                v[fi][0]=fi;
                indegree[fi]++;
                indegree[ai]++;
            }
        }
    }

    // for(int i=0;i<8;i++){
    //     cout<<indegree[i]<<' ';
    // }
    // cout<<'\n';

    for(int i=0;i<8;i++){
        if(indegree[i]) continue;
        
        q.push(i);
        //cout<<"a: "<<i<<'\n';

        while(!q.empty()){
            int a=q.front();
            indegree[a]=-1;
            q.pop();
            int sz=v[a].size();
            cout<<intToString[a]<<'\n';

            for(int j=0;j<sz;j++){
                //cout<<v[a][j]<<'\n';
                indegree[v[a][j]]--;
                if(!indegree[v[a][j]]) q.push(v[a][j]);
            }
        }

        
    }


    return 0;
}