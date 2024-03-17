#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[5];
int x;

int main() {
    cin>>arr[0]>>arr[1]>>arr[2];
    int num=0;

    while(1){
        sort(arr,arr+3);
        //연속일 경우, 그대로
        if(arr[0]+1==arr[1]&&arr[1]+1==arr[2]) break;
        //3개중 2개만 연속일 경우, 연속된 것 중 끝쪽 선택
        else if(arr[0]+1==arr[1]){
            arr[0]=(arr[1]+arr[2]+1)/2;
            num++;
        }
        else if(arr[1]+1==arr[2]){
            arr[2]=(arr[1]+arr[0]+1)/2;
            num++;
        }
        //다 떨어져있을 경우, 가운데랑 거리가 먼 곳 선택
        else{
            if(arr[1]-arr[0]>arr[2]-arr[1]){
                arr[0]=(arr[1]+arr[2]+1)/2;
                num++;
            }
            else{
                arr[2]=(arr[1]+arr[0]+1)/2;
                num++;
            }
        }
    }

    cout<<num;

    return 0;
}