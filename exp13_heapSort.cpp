#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
}
void heapSort(vector<int>& arr, int n){
    int size = n;
    while(size>1){
    swap(arr[0], arr[size-1]);
    size--;
    heapify(arr, size, 0);
    }
}
void print(vector<int>&v){
    for(auto ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v = {5,4,2,3,1};

    int n = v.size();

    for(int i = n/2; i >= 0; i--){
        heapify(v, n, i);
    }
    heapSort(v, n);

    print(v);

}