#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k,x;
string n,s;
vector<int> v;

string repeat(int c, int len){
    string s="";
    for(int i=0;i<len;i++){
        s+=to_string(c);
    }
    return s;
}

string proc(){
    int sz=n.size();
    string s=repeat(v[0],sz);
    
    if(s>n){
        return repeat(v[k-1],sz-1);
    }

    s="";
    
    for(int i=0;i<sz;i++){
        for(int j=k-1;j>=0;j--){
            if(s+to_string(v[j])+repeat(v[0],sz-i-1)<=n){
                s+=to_string(v[j]);
                break;
            }
        }
    }

    return s;
}

int main() {
    
    cin>>n>>k;

    for(int i=0;i<k;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    cout<<proc();

    

    return 0;
}
