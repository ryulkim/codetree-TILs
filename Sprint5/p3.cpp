#include <iostream>
using namespace std;

bool valid(int y){
    if(y%4==0){
        if(y%100==0){
            if(y%400==0) return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

int main() {
    int y1,y2,m1,m2,d1,d2;
    int day[15]={31,28,31,30,31,30,31,31,30,31,30,31};

    cin>>y1>>m1>>d1;
    cin>>y2>>m2>>d2;

    int d=(y2-y1)*365;

    for(int i=y1;i<y2;i++){
        if(i%4==0&&valid(i)) d++;
    }

    for(int i=0;i<m1-1;i++){
        d-=day[i];
    }

    if(m1>2&&valid(y1)) d-=1;
    d-=(d1-1);

    for(int i=0;i<m2-1;i++){
        d+=day[i];
    }

    if(m2>2&&valid(y2)) d+=1;
    d+=d2;

    cout<<d;

    return 0;
}
