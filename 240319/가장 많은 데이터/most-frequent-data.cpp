#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
string s;
unordered_map<string, int> u;
int ans=0;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        u[s]++;
        ans=max(ans,u[s]);
    }

    cout<<ans;
    
    return 0;
}