#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    int n,x;
    string s;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;

        if(s=="push_back"){
            cin>>x;
            d.push_back(x);
        }
        else if(s=="push_front"){
            cin>>x;
            d.push_front(x);
        }
        else if(s=="pop_front"){
            cout<<d.front()<<'\n';
            d.pop_front();
        }
        else if(s=="pop_back"){
            cout<<d.back()<<'\n';
            d.pop_back();
        }
        else if(s=="size"){
            cout<<d.size()<<'\n';
        }
        else if(s=="empty"){
            cout<<d.empty()<<'\n';
        }
        else if(s=="front"){
            cout<<d.front()<<'\n';
        }
        else if(s=="back"){
            cout<<d.back()<<'\n';
        }

    }
    return 0;
}