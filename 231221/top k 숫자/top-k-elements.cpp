#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,k,x;
    set<int> s;
    set<int>::reverse_iterator it;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    
    int i;

    for(it=s.rbegin(),i=0;it!=s.rend();it++,i++){
        if(k==i)break;
        cout<<*it<<" ";
    }


    return 0;
}