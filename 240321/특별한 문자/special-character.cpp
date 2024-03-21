#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

unordered_map<char, int> a,b;
vector<char> v;

bool cmp(char x, char y){
    if(b[x]<b[y]) return true;
    return false;
}

int main() {
    string s;
    
    cin>>s;

    int sz=s.size();

    for(int i=0;i<sz;i++){
        a[s[i]]++;
        if(b.find(s[i])==b.end()){
            b[s[i]]=i;
        }
    }

    for(auto t: a){
        if(t.second==1){
            v.push_back(t.first);
        }
    }

    sort(v.begin(), v.end(), cmp);

    int vsz=v.size();

    for(int i=0;i<vsz;i++){
        cout<<v[i]<<' ';
    }

    return 0;
}