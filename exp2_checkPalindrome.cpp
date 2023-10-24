#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n = s.length();

    int i = 0, j = n-1;

    while(i < j){
        if(s[i] != s[j]){
            cout<<"No"<<endl;
            return 0;
        }
        i++;
        j--;
    }
    cout<<"Yes"<<endl;
    return 0;
}