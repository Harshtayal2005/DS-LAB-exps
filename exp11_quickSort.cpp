#include<iostream>
using namespace std;

int partition(int arr[], int si, int ei){
    int pivot = si;
    int count = 0;
    for(int i=si+1; i<=ei; i++){
        if(arr[i] <= arr[pivot]){
            count++;
        }
    }
    int pivotIndex = si + count;
    swap(arr[pivotIndex], arr[si]);
    int i = si, j = ei;
    while(i < pivotIndex && j > pivotIndex){
        if(arr[i] > arr[pivotIndex] && arr[j] <= arr[pivotIndex]){
            swap(arr[i++], arr[j--]);
        }
        else if(arr[i] <= arr[pivotIndex]){
            i++;
        }
        else if(arr[j] > arr[pivotIndex]){
            j--;
        }
    }
    return pivotIndex;
}

void qSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int pi = partition(arr, si, ei);
    
    //left sort
    qSort(arr, si, pi-1);
    //right sort
    qSort(arr, pi+1, ei);
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {3,2,1,5,4};
    int n = 5;
    qSort(arr, 0, n-1);
    print(arr, n);
    return 0;
}