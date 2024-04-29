#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> v[15];
int n,m,q,a,b;
int num=1;

int main() {
    cin>>n>>m>>q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n/m;j++){
            v[i].push_back(num++);
        }
    }

    for(int i=0;i<q;i++){
        int way;
        cin>>way;
        if(way==1){
            cin>>a;
            if(v[a].empty()) continue;
            v[a].push_back(v[a].front());
            v[a].pop_front();
        }
        else if(way==2){
            cin>>a;
            if(v[a].empty()) continue;
            v[a].push_front(v[a].back());
            v[a].pop_back();
        }
        else{
            cin>>a>>b;
            int sz=v[a].size();
            for(int i=0;i<sz;i++){
                v[b].push_front(v[a].back());
                v[a].pop_back();
            }
        }
    }

    for(int i=0;i<m;i++){
        int sz=v[i].size();
        if(sz==0){
            cout<<-1<<'\n';
            continue;
        }
        else{
            while(!v[i].empty()){
                cout<<v[i].front()<<' ';
                v[i].pop_front();
            }
            cout<<'\n';
        }

    }

    return 0;
}
