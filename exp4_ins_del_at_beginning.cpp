#include<iostream>
#include<vector>
using namespace std;

void deleteAtStart(vector<int>& arr, int& n){

    if(n == 0){
        cout<<"Underflow\n";
        return ;
    }

    for(int i = 0 ; i < n - 1 ; i++){

        if(i >= 0){
            arr[i] = arr[i+1];
        }
    }

    n = n-1;
}

void print(vector<int> arr, int n){

    for(int i  = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void insertAtStart(vector<int> &arr, int& n,int elmt){

    if(n==arr.size()){
        cout<<"Overflow\n";
        return ;
    }
    for(int i = n; i >= 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0]=elmt;
    n = n+1;

}
int main(){
    //for insertion 
    vector<int> arr={4, 7, 8, 9, 10};

    int n = 5;

    deleteAtStart(arr,n);

    print(arr,n);

    int elemt;

    cout<<"ELEMENT TO BE INSERTED : \n";

    cin>>elemt;

    insertAtStart(arr,n,elemt);

    print(arr,n);

    return 0;
}