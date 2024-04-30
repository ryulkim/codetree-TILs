#include <iostream>
#include <vector>
using namespace std;

string s;
int n;
vector<string> v;

int main() {
    for(int i=0;i<4;i++){
        cin>>s;
        v.push_back(s);
    }

    int num=0;
    while(num<15){
        for(int i=0;i<4;i++){
            if(v[i].size()<=num) continue;
            cout<<v[i][num];
        }
        num++;
    }
    

    return 0;
}
