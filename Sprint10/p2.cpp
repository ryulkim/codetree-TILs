#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,k,t,s,x,y,z;
priority_queue<tuple<int, int, int>> a,b; //시간, 물건, 숫자, //물건, 시간, 숫자

int main() {
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>t>>s;
        a.push({-t,s,i});
    }
    int time=0;
    while(!a.empty()){
        tie(x,y,z)=a.top();
        if(-x>time&&b.empty()) time=-x;
        if(-x<=time) {
            b.push({y,x,z});
            // cout<<time<<' '<<y<<' '<<-x<<' '<<z<<'\n';
            a.pop();
        }

        int x1,y1,z1;
        tie(x1,y1,z1)=a.top();
        while(!a.empty()&&x==x1){
            b.push({y1,x1,z1});
            // cout<<time<<' '<<y1<<' '<<x1<<' '<<z1<<'\n';
            a.pop();
            tie(x1,y1,z1)=a.top();
        }

        // cout<<"x1: "<<x1<<'\n';
    
        while(!b.empty()&&-x1>time){
            int x2,y2,z2;
            tie(y2,x2,z2)=b.top();
            time+=k;
            b.pop(); 
            // cout<<time<<' '<<y1<<' '<<x1<<' '<<z1<<'\n';  
            cout<<z2<<' ';
        }
        // cout<<'\n';
        
    }

    while(!b.empty()){
        tie(y,x,z)=b.top();
        if(-x<=time) {
            cout<<z<<' ';
            b.pop();
        }
        
    }

    return 0;
}
