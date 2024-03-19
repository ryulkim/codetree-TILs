#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n,k,v;
    string s;
    unordered_map<int, int> u;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;

        if(s=="add"){
            cin>>k>>v;
            u[k]=v;
        }
        else if(s=="remove"){
            cin>>k;
            u.erase(k);
        }
        else if(s=="find"){
            cin>>k;
            if(u.find(k)!=u.end()){
                cout<<u[k]<<'\n';
            }
            else{
                cout<<"None\n";
            }
        }
    }
    return 0;
}