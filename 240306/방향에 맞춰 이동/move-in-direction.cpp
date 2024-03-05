#include <iostream>
using namespace std;

int main() {
    int n,d,x=0,y=0;
    char c;
    int dx[6]={0,0,1,-1};
    int dy[6]={1,-1,0,0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>d;
        if(c=='N'){
            y+=dy[0]*d;
        }
        else if(c=='E'){
            x+=dx[2]*d;
        }
        else if(c=='S'){
            y+=dy[1]*d;
        }
        else{
            x+=dx[3]*d;
        }
    }

    cout<<x<<' '<<y;

    return 0;
}