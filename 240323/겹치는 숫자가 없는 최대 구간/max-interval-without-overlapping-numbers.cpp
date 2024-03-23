#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,x;
vector<int> v;
int cnt[100005];
int ans=0;

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    int j=-1;
    int len=0;
    for(int i=0;i<n;i++){
        while(j+1<n&&cnt[v[j+1]]==0){
            cnt[v[j+1]]++;
            j++;
            len++;
        }
        ans=max(ans, len);
        cnt[v[i]]--;
        len--;
        
    }

    cout<<ans;

    return 0;
}