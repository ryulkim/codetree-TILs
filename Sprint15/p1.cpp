#include <iostream>
using namespace std;

string a,b;
int arr[405];

int main() {
    cin>>a>>b;

    int sz=a.size();

    for(int i=0;i<sz;i++){
        if(a[i]==b[0]){
            arr[i]=1;
        }
    }

    bool turn=1;
    int bsz=b.size();

    while(turn){
        turn=0;

        for(int i=0;i<sz;i++){
            if(arr[i]!=1) continue;

            bool chk=1; 
            arr[i]=-1;
            
            if(bsz==1) {
                turn=1;
                continue;
            }

            for(int j=i+1;j<sz;j++){
                if(arr[j]!=-1&&a[j]!=b[1]){
                    arr[i]=1;
                    break;
                }
                else if(arr[j]!=-1&&a[j]==b[1]){
                    arr[j]=-1;
                    turn=1;
                    break;
                }
            }
        }
    }

    for(int i=0;i<sz;i++){
        if(arr[i]!=-1) cout<<a[i];
    }

    return 0;
}
