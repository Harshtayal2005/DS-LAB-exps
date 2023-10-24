#include<iostream>
using namespace std;

int search(int arr[], int n, int key){
    int si = 0;
    int ei = n-1;
    int mid = si + (ei-si)/2;

    while(si <= ei){
        if(key==arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            si = mid+1;
        }
        else{
            ei = mid-1;
        }
        mid = si + (ei-si)/2;
    }
    return -1;
}
int main(){
    int arr[]={2,9,10,11,15}; //always for sorted array
    int n = 5;
    int key = 1;
    int ans = search(arr, n, key);
    switch(ans){
        case -1:
                cout<<"Key not found"<<endl;
                break;

        default:
                cout<<"Key found at index: "<<ans<<endl;
    }
    return 0;
}