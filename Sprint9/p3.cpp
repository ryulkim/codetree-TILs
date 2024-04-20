#include <iostream>

using namespace std;

int dr[6]={0,1,0,-1};
int dc[6]={1,0,-1,0};
int arr[105][105];

int n;


int main() {
    cin>>n;

    int ia=0,ib=n-1,ja=0,jb=n-1,num=0;

    while(ia<=ib&&ja<=jb){
        int i=ia,j=ja;
        num++;

        if(ia==ib) {
            arr[i][j]=num;
            break;
        }

        for(int k=0;k<4;k++){    
            while(i<=ib&&i>=ia&&j<=jb&&j>=ja){
                if(k==3&&i==ia) break;
                arr[i][j]=num++;
                i+=dr[k];
                j+=dc[k];
            }
            i-=dr[k];
            j-=dc[k];
            num--;
        }

        ia++;ib--;ja++;jb--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
