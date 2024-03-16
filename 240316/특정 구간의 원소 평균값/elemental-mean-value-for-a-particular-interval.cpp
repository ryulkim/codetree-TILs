#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,x,ans=0;
    vector<int> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int num=0;
            for(int k=i;k<=j;k++){
                num+=v[k];
            }
            if(num%(j-i+1)!=0) continue;
            num/=j-i+1;
            for(int k=i;k<=j;k++){
                if(num==v[k]){
                    ans++;
                    //cout<<i<<' '<<j<<'\n';
                    break;
                }
            }
        }
    }

    cout<<ans;
    return 0;
}