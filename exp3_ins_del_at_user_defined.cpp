#include<iostream>
#include<vector>
using namespace std;

void delete_element(vector<int>& arr, int& n,int poss){

    if(n == 0){
        cout<<"Underflow\n";
        return ;
    }

    for(int i = 0 ; i < n - 1 ; i++){

        if(i >= poss){
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

void insert(vector<int> &arr, int& n,int elmt,int pos){

    if(n==arr.size()){
        cout<<"Overflow\n";
        return ;
    }
    for(int i = n; i >= pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos]=elmt;
    n = n+1;

}
int main(){
    //for insertion 
    vector<int> arr={23,24,25,26,27};

    int n = 5;

    delete_element(arr,n,2);

    print(arr,n);

    int elemt,poss;

    cout<<"ELEMENT TO BE INSERTED : \n";

    cin>>elemt>>poss;

    insert(arr,n,elemt,poss);

    print(arr,n);

    return 0;
}