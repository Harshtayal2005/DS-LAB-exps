#include<iostream>
using namespace std;

int main(){
    //n is no of students
    int n;
    cout<<"Enter the no of students: ";
    cin>>n;
    int m = 5; //m is total no of subjects
    int arr[n][m];
    for(int i=0; i<n; i++){
        cout<<"Enter the marks of student "<<i+1<<" : "<<endl;
        for(int j=0; j<m; j++){
            
            cin>>arr[i][j];
            
        }
        int sum=0;
        for(int k=0; k<m; k++){
            sum+=arr[i][k];
        }
        cout<<"total marks of student "<<i+1<<" is: "<<sum<<endl;
    }
    float avg;
    
    int temp = 0;
    float total = 0;
    for(int i=0; i<m; i++){
        float sum=0;
        for(int j=0; j<n; j++){
        sum+=arr[j][temp];
        
        }
        avg = sum/n;
        total+=avg;
        cout<<"average of sub "<<i+1<<" is: "<<avg<<endl;
        temp++;

    }
    
    cout<<"total average is: "<<total/n<<endl;
    return 0;
}