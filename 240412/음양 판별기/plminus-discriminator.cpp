#include <iostream>
using namespace std;

int n,x;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0) cout<<"zero\n";
        else if(x>0) cout<<"plus\n";
        else cout<<"minus\n";
    }
    return 0;
}