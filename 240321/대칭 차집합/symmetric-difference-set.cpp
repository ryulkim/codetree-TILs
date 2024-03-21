#include <iostream>
#include <unordered_set>
using namespace std;

int a,b,x;
unordered_set<int> u;

int main() {
    cin>>a>>b;

    for(int i=0;i<a;i++){
        cin>>x;
        u.insert(x);
    }

    for(int i=0;i<b;i++){
        cin>>x;
        if(u.find(x)!=u.end()){
            u.erase(x);
        }
        else{
            u.insert(x);
        }
    }

    cout<<u.size();
    
    return 0;
}