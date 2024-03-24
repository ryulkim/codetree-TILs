#include <iostream>
#include <vector>
using namespace std;

int n,m,x;
vector<int> a,b;

bool proc(){
    int i=0;

    for(int j=0;j<m;j++){
        while(i<n&&a[i]!=b[j]){
            i++;
        }
        if(i==n) return false;
        else i++;
    }
    return true;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }

    for(int i=0;i<m;i++){
        cin>>x;
        b.push_back(x);
    }

    if(proc()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}