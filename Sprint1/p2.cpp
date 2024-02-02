#include <iostream>
#include <vector>
#define sz 305
using namespace std;

int arr[sz][sz];
int ans[sz][sz];
pair<int,int> dir[5]={{1,0},{0,1},{-1,0},{0,-1}};
vector<pair<int,int>> v[sz];
bool visited[sz][sz];
int n,m,k;

void proc(){
    for(int i=0;i<n;i++){
        int r=i, c=i, d=0;

        if(visited[r][c]) break;

        v[i].push_back({i,i});
        visited[i][i]=1;

    
        while(true){
            int nr=r+dir[d].first;
            int nc=c+dir[d].second;

            if(nr>=n||nc>=m||nr<0||nc<0||visited[nr][nc]){
                d++;
            }
            
            if(d==4) break;

            nr=r+dir[d].first;
            nc=c+dir[d].second;

            if(visited[nr][nc]) break;
            
            //cout<<"nr: "<<nr<<" nc: "<<nc;
            v[i].push_back({nr,nc});
            r=nr;
            c=nc;
            visited[r][c]=1;
        }

        if(d<3){
            for(auto p: v[i]){
                ans[p.first][p.second]=arr[p.first][p.second];
            }
            v[i].clear();
        }



    }

}

int main() {
    
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    proc();

    for(int i=0;i<n;i++){
        int len=v[i].size();

        //if(len==0) break;
        
        for(int j=0;j<len;j++){
            int r=v[i][j].first;
            int c=v[i][j].second;

            int nr=v[i][(j+k)%len].first;
            int nc=v[i][(j+k)%len].second;

            ans[nr][nc]=arr[r][c];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
