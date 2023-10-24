#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int trap(vector<int>& height) {
    vector<int> mxl;
    vector<int> mxr;
    int n = height.size();
    int maxi = height[0];
    mxl.push_back(height[0]);
    for(int i=1; i<n; i++){
        if(height[i]>maxi) maxi = height[i];
        mxl.push_back(maxi);
    }
    //print(mxl);
    maxi = height[n-1];
    mxr.push_back(height[n-1]);
    for(int i = n-2; i>=0; i--){
        if(height[i]>maxi) maxi = height[i];
        mxr.push_back(maxi);
    }
    reverse(mxr.begin(), mxr.end());
    //print(mxr);
    vector<int> water;
    int ans=0;
    for(int i=0; i<n; i++){
        water.push_back(min(mxl[i], mxr[i]) - height[i]);
    }
    for(int i=0; i<water.size(); i++){
        ans += water[i];
    }
    //print(water);
    return ans;
}

int main(){

    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<trap(v)<<endl;

    return 0;
}