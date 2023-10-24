#include<iostream>
using namespace std;

void merge(int arr[], int si, int ei, int mid){
    int i = si, j = mid+1, k = 0;
    int m = mid-si+1;
    int n = ei-mid;
    int *sortedArray = new int[m+n];
    
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            sortedArray[k++] = arr[i++];
        }
        else if(arr[i]>arr[j]){
            sortedArray[k++] = arr[j++];
        }
    }
    while(i<=mid){
        sortedArray[k++] = arr[i++];
    }
    while(j<=ei){
        sortedArray[k++] = arr[j++];
    }
    for(int idx = 0 ; idx<(ei-si+1); idx++){
        arr[idx+si] = sortedArray[idx];
    }
    delete[] sortedArray;
}

void mergeSort(int arr[], int si, int ei){
    if(si>=ei){
        return ;
    }
    int mid = si + (ei - si)/2;
    // left sorting
    mergeSort(arr, si, mid);
    //right sorting
    mergeSort(arr, mid+1, ei);
    merge(arr, si, ei, mid);
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]= {5,5,4,3,2,1};
    int n = 6;
    mergeSort(arr, 0, n-1);
    print(arr, n);
    return 0;
}