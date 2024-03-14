#include <iostream>
using namespace std;

int main() {
    int n,m, ans=0;
    int arr[105][105]={0,};
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }


    for(int i=0;i<n;i++){
        int num=arr[i][0];
        int cnt=0;

        for(int j=0;j<n;j++){
            if(num==arr[i][j]){
                cnt++;
            }
            else{
                num=arr[i][j];
                cnt=1;
            }

            if(cnt==m) {
                ans++;
                //cout<<"가로: "<<i<<'\n';
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        int num=arr[0][i];
        int cnt=0;

        for(int j=0;j<n;j++){
            if(num==arr[j][i]){
                cnt++;
            }
            else{
                num=arr[j][i];
                cnt=1;
            }

            if(cnt==m) {
                ans++;
                //cout<<"세로: "<<i<<'\n';
                break;
            }
        }
    }

    cout<<ans;
    

    return 0;
}