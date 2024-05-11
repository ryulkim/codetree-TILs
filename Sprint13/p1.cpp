#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string s;
vector<string> v;

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0;i<n;i++){
        cout<<v[i]<<'\n';
    }

    return 0;
}
