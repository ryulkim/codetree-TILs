#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int x,y,a,b;
int ans=1e9;

int main() {
    cin>>a>>b>>x>>y;
    //A->B
    ans=min(ans, b-a);
    //A->X->Y->B
    ans=min(ans, abs(a-x)+abs(b-y));
    //A->Y->X->B
    ans=min(ans, abs(a-y)+abs(b-x));

    cout<<ans;

    return 0;
}