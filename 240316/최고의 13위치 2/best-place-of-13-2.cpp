#include <iostream>
#include <algorithm>
using namespace std;

int n, ans=0;
bool arr[25][25];

int main() {

    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int ii=0;ii<n;ii++){
                if(ii<i) continue;
                for(int jj=0;jj<n;jj++){
                    if(ii==i&&jj<=j+2) continue;
                    ans=max(ans,arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[ii][jj]+arr[ii][jj+1]+arr[ii][jj+2]);
                }
            }
        }
    }

    cout<<ans;

    return 0;
}