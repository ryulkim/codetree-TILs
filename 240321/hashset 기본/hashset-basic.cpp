#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> u;
int n,x;
string s;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;

        if(s=="add"){
            cin>>x;
            u.insert(x);
        }
        else if(s=="remove"){
            cin>>x;
            u.erase(x);
        }
        else if(s=="find"){
            cin>>x;
            if(u.find(x)==u.end()){
                cout<<"false\n";
            }
            else{
                cout<<"true\n";
            }
        }
    }

    return 0;
}