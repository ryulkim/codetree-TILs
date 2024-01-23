#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<int> v;
    int a=0, b=0;
    cin>>s;

    int sz=s.size();

    if(s[0]=='('){
        v.push_back(1);
    }
    else if(s[0]==')'){
        v.push_back(-1);
    }

    for(int i=1;i<sz;i++){
        if(s[i]=='('){
            if(v[i-1]>0){
                v.push_back(v[i-1]+1);
            }
            else v.push_back(1);
        }
        else if(s[i]==')'){
            if(v[i-1]>0){
                v.push_back(-1);
            }
            else v.push_back(v[i-1]-1);
        }
    }

    for(int i=0;i<sz;i++){
        if(v[i]>1) a++;
        else if(v[i]<-1) b++;
    }

    cout<<a*b;

    return 0;
}