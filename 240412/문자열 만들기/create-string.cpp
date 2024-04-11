#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    string s,t="";

    cin>>n>>s;

    int end=n-1;
    for(int i=0;i<end;i++){
        while(1){
            if(s[i]<s[end]) {
                t+=s[i];
                break;
            }
            t+=s[end--];
        }
    }

    t+=s[end];

    cout<<t;

    return 0;
}