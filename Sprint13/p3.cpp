#include <iostream>
using namespace std;

long long n;

int proc(int one, int two){
    long long f=1;
    long long l=n;
    long long m=(f+l)/2;
    long long result=(f+l)/2;
    long long num;

    while(1){
        num=one*result;
        result+=num/two;
        result-=num/15;

        if(result==n) {
            return num;
        }

        if(f==l) return -1;

        if(result>n){
            if(l==m) return -1;
            l=m;
        }
        else{
            if(f==m) return -1;
            f=m;
        }
        m=(f+l)/2;
        result=m;
    }
}

int main() {
    cin>>n;

    
    long long num=proc(3,5);

    if(num!=-1) cout<<num<<'\n';
    else{
        cout<<proc(5,3)<<'\n';
    }
    

    return 0;
}
