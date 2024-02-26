#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool chk[15];
int n,k,x;
set<string> s;
vector<int> v;

void ans(string a, int lev){
    if(lev==k){
        s.insert(a);
        return;
    }

    for(int i=0;i<n;i++){
        if(chk[i]) continue;
        chk[i]=1;
        ans(a+to_string(v[i]),lev+1);
        chk[i]=0;
    }
}

int main() {
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    ans("",0);

    cout<<s.size();

    return 0;
}
