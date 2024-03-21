#include <iostream>
#include <unordered_set>
using namespace std;

int n,x;
unordered_set<int> u;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        u.insert(x);
    }

    cout<<u.size();
    
    return 0;
}