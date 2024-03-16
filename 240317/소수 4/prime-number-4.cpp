#include <iostream>
using namespace std;

int n,k;
int arr[1005];

int proc(){
    int num=0;

    for(int i=2;i<=n;i++){
        if(arr[i]==1) continue;
        for(int j=i;j<=n;j++){
            if(j%i==0&&arr[j]==0){
                //cout<<j<<' ';
                arr[j]=1;
                num++;
                if(num==k) return j;
            }
            
        }
    }
}

int main() {
    
    cin>>n>>k;
    
    cout<<proc();
    
    return 0;
}