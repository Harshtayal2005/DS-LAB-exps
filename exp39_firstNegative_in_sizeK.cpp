#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long int> ans;
    for(int i=0; i<K; i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    for(int i=K; i<N; i++){
        if(!dq.empty() && i-dq.front()>=K){
            dq.pop_front();
        }
        if(A[i]<0){
            dq.push_back(i);
        }
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
    }
    return ans;
    
 }

int main(){
    long long int arr[]={-1,3,4,5,-2,-3};
    long long int n = 6;
    long long int K = 2;
    vector<long long> ans;
    ans = printFirstNegativeInteger(arr, n, K);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}