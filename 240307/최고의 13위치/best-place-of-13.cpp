#include <iostream>
using namespace std;

int main() {
    int n, ans=0;
    bool arr[25][25]={0,};
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j+2>n) continue;
            ans=max(ans, arr[i][j]+arr[i][j+1]+arr[i][j+2]);
        }
    }

    cout<<ans;

    return 0;
}