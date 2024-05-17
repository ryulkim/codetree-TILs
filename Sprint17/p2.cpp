#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n,m,v,w;
double v1;
double ans=0;
priority_queue<pair<double, int>> q; //무게 단위 1당 가치, 총 무게

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>w>>v;
        double d=(double) v/w;
        q.push({d,w});
    }

    while(!q.empty()&&m){
        tie(v1,w)=q.top();
        q.pop();

        if(m>=w){
            m-=w;
            ans+=v1*w;
        }
        else{
            ans+=v1*m;
            m=0;
        }
    }

    cout<<fixed;
    cout.precision(3);
    cout<<ans;

    return 0;
}
