#include<iostream>
using namespace std;

int search(int arr[], int key, int n){
    for(int i=0; i<n; i++){
        if(key == arr[i])
            return i;
    }
    return -1;
}
int main(){
    int arr[]={3,4,2,1,5};
    int n = 5;
    int key = 1;
    int ans = search(arr, key, n);
    switch(ans){
        case -1:
                cout<<"Key not found"<<endl;
                break;
        
        default:
                cout<<"Key found at index: "<<ans<<endl;
    }
    return 0;
}