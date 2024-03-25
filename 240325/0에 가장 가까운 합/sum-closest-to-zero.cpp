#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,x,ans=1e9;
vector<int> pl, mi;

void proc(){
    int msz=mi.size();
    int psz=pl.size();
    int j=0;
    int sum=abs(mi[0]+pl[0]);
    ans=sum;

    for(int i=0;i<psz;i++){
        while(j+1<msz&&sum>abs(pl[i]+mi[j+1])){
            j++;
        }

        ans=min(ans, abs(pl[i]+mi[j]));
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(x>=0) pl.push_back(x);
        else mi.push_back(x);
    }

    sort(pl.begin(), pl.end());
    sort(mi.begin(), mi.end(),greater<int>());

    if(pl.size()==0) cout<<-(mi[0]+mi[1]);
    else if(mi.size()==0) cout<<pl[0]+pl[1];
    else{
        proc();
        cout<<ans;
    }

    return 0;
}