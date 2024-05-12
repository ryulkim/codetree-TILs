#include <iostream>
using namespace std;

int n;
string s;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        int sz=s.size();
        bool chk=0;
        int sum=0;

        for(int j=0;j<sz;j++){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') {
                chk=1;
                if(sum<0) sum=1;
                else sum++;
            }
            else{
                if(sum>0) sum=-1;
                else sum--;
            }

            if(sum==3||sum==-3) {
                chk=0;
                break;
            }

            if(j>0&&s[j]!='e'&&s[j]!='o'){
                if(s[j]==s[j-1]){
                    chk=0;
                    break;
                }
            }
        }

        cout<<chk<<'\n';
    }
    return 0;
}
