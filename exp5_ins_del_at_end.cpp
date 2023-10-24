#include<iostream>
#include<vector>
using namespace std;

void deleteAtEnd(vector<int>& arr, int& n){

    if(n == 0){
        cout<<"Underflow\n";
        return ;
    }

    n = n-1;
}

void print(vector<int> arr, int n){

    for(int i  = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void insertAtEnd(vector<int> &arr, int& n,int elmt){

    if(n==arr.size()){
        cout<<"Overflow\n";
        return ;
    }
    arr[n]=elmt;
    n = n+1;

}
int main(){
    //for insertion 
    vector<int> arr={4, 7, 8, 9, 10};

    int n = 5;

    deleteAtEnd(arr,n);

    print(arr,n);

    int elemt;

    cout<<"ELEMENT TO BE INSERTED : \n";

    cin>>elemt;

    insertAtEnd(arr,n,elemt);

    print(arr,n);

    return 0;
}