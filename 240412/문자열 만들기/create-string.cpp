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
            if(s[i]==s[end]){
                int a=i;
                int b=end;
                while(a<b&&s[a]==s[b]){
                    a++; b--;
                }
                if(a>=b) {
                    t+=s[i];
                    break;
                }
                else if(s[a]<s[b]){
                    t+=s[i];
                    break;
                }
                else{
                    t+=s[end--];
                }
            }
            else if(s[i]<s[end]) {
                t+=s[i];
                break;
            }
            t+=s[end--];
            if(i==end) break;
        }
    }

    t+=s[end];

    cout<<t;

    return 0;
}