#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n,x, ans=0;
    vector<int> a,b,c,d;
    unordered_map<int, int> one;

    cin>>n;


    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        c.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        d.push_back(x);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            one[a[i]+b[j]]++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t=-c[i]-d[j];

            ans+=one[t];
        }
    }

    cout<<ans;

    return 0;
}