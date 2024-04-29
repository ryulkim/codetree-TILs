#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int n;
string s;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        unordered_map<char, int> u;
        unordered_map<char, int>::iterator it;
        priority_queue<pair<int, char>> q;
        cin>>s;
        for(int j=0;j<s.size();j++){
            u[s[j]]++;
        }
        for(it=u.begin();it!=u.end();it++){
            q.push({(*it).second,(*it).first});
        }
        int num=q.top().first;
        char answer=q.top().second;
        q.pop();
        if(q.top().first==num){
            answer='?';
        }
        cout<<answer<<'\n';
    }
    return 0;
}
