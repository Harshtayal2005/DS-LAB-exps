#include<iostream>
using namespace std;

void iSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {3,2,1,4,5};
    int n = 5;
    iSort(arr, n);
    print(arr, n);
    return 0;
}