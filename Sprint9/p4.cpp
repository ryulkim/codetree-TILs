#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,k,x,num,t,cnt=0;
priority_queue<tuple<int,int,int>> q; //시간, 계산기, 사람

int main() {
    cin>>n>>k>>x;

    for(int i=1;i<=k;i++){
        q.push({0,-i,0});
    }

    for(int i=0;i<n;i++){

        cin>>num>>t;

        int a,b,c;
        tie(a,b,c)=q.top();
        q.pop();
        q.push({a-t, b, num});
        
        if(c!=0){
            cnt++;
        }

        if(cnt==x){
            cout<<c;
        }
    }

    if(cnt<x){
        while(!q.empty()){
            int a,b,c;
            tie(a,b,c)=q.top();
            q.pop();
            
            if(c!=0){
                cnt++;
            }

            if(cnt==x){
                cout<<c;
                break;
            }
        }
    }
    

    return 0;
}
