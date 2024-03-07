#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n,x;
    int m=1e9;
    vector<int> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=abs(i-j)*v[j];
        }
        m=min(sum,m);
    }

    cout<<m;

    return 0;
}