#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    string s;
    deque<char> d,t;

    cin>>n>>s;

    int sz=s.size();

    for(int i=0;i<sz;i++){
        d.push_back(s[i]);
    }

    while(!d.empty()){
        int a=d.front();
        int b=d.back();

        if(a<b){
            d.pop_front();
            t.push_back(a);
        }
        else{
            d.pop_back();
            t.push_back(b);
        }
    }

    while(!t.empty()){
        cout<<t.front();
        t.pop_front();
    }

    return 0;
}