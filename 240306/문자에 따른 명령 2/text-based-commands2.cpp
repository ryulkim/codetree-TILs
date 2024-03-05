#include <iostream>
using namespace std;

int main() {
    int x=0,y=0,n,dir=0;
    string s;
    int dx[5]={0,1,0,-1};
    int dy[5]={1,0,-1,0};

    cin>>s;

    int sz=s.size();

    for(int i=0;i<sz;i++){
        if(s[i]=='L'){
            dir=(dir+3)%4;
        }
        else if(s[i]=='R'){
            dir=(dir+1)%4;
        }
        else{
            x+=dx[dir];
            y+=dy[dir];
        }
    }

    cout<<x<<' '<<y;

    return 0;
}