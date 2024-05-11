#include <iostream>
using namespace std;

int n,q,t,l,r;
int water[100005];
int plant[100005];

int main() {
    cin>>n>>q>>t;

    for(int i=0;i<q;i++){
        cin>>l>>r;
        water[l]++;
        water[r+1]--;
    }

    bool chk=0;

    for(int i=1;i<=n;i++){
        plant[i]=plant[i-1]+water[i];
        if(plant[i]==t) {
            chk=1;
            cout<<i<<' ';
        }
    }

    if(!chk) cout<<-1;

    return 0;
}
