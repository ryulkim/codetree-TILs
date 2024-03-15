#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int ans=0;
    string s;
    vector<string> v;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sz=min(v[i].size(), v[j].size());
            int isz=v[i].size()-1;
            int jsz=v[j].size()-1;
            string temp="";
            if(isz>jsz){
                temp=v[i];
            }
            else{
                temp=v[j];
            }
            bool chk=0;

            for(int k=0;k<sz;k++){
                if(v[i][isz-k]-'0'+v[j][jsz-k]-'0'>9){
                    chk=1;
                    break;
                }
                temp[temp.size()-k-1]=(v[i][isz-k]-'0'+v[j][jsz-k]);

            }

            if(chk) continue;

            //cout<<"1: "<<v[i]<<' '<<v[j]<<' '<<temp<<'\n';

            for(int k=j+1;k<n;k++){
                int sz=min(v[k].size(), temp.size());
                int ksz=v[k].size()-1;
                int tsz=temp.size()-1;
                bool chk=0;
                string ans_temp="";
                if(ksz>tsz){
                    ans_temp=v[k];
                }
                else{
                    ans_temp=temp;
                }

                for(int l=0;l<sz;l++){
                    if(temp[tsz-l]-'0'+v[k][ksz-l]-'0'>9){
                        chk=1;
                        break;
                    }
                    ans_temp[ans_temp.size()-l-1]=(v[k][ksz-l]-'0'+temp[tsz-l]);
                }

                if(chk) continue;
                //cout<<v[i]<<' '<<v[j]<<' '<<v[k]<<'\n';
                ans=max(ans,stoi(ans_temp));
            }
        }
    }

    if(ans==0){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    return 0;
}