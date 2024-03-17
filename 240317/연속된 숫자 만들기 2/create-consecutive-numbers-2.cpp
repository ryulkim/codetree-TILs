#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[5];
int x;

int main() {
    cin>>arr[0]>>arr[1]>>arr[2];
    int num=0;

    sort(arr, arr+3);

    if(arr[0]+1==arr[1]&&arr[1]+1==arr[2]) cout<<0;
    else if(arr[0]+2==arr[1]||arr[1]+2==arr[2]) cout<<1;
    else cout<<2;

    return 0;
}