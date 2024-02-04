#include <iostream>
using namespace std;

int main() {
    int n,m=0;
    cin>>n;

    for(int i=1;i<n;i++){
        int sum=i;
        int a=i;

        while(a){
            sum+=a%10;
            a/=10;
        }

        if(sum==n) {
            m=i;
            break;
        }
    }

    if(m==0) cout<<0;
    else cout<<m;

    return 0;
}
