#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(vector<int>& v){
    for(int x : v) cout<<x<<" ";
    cout<<endl;
}

vector<int> NGR(vector<int> &v){
    stack<int> s;
    int n = v.size();
    vector<int> ngr(n);

    for(int i = n-1; i >=0; i--){
        while(!s.empty() && v[s.top()] <= v[i]) s.pop();
        ngr[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    //reverse(begin(ngr), end(ngr));
    return ngr;
}

vector<int> NSL(vector<int> &v){
    stack<int> s;

    int n = v.size();
    vector<int> nsl(n);

    for(int i = 0; i < n; i++){
        while(!s.empty() && v[i] <= v[s.top()]) s.pop();
        nsl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return nsl;
}

vector<int> NSR(vector<int> &v){
    stack<int> s;

    int n = v.size();
    vector<int> nsr(n);

    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && v[i] <= v[s.top()]) s.pop();
        nsr[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    //reverse(begin(nsr), end(nsr));
    return nsr;
}

vector<int> NGL(vector<int> &v){
    stack<int> s;
    int n = v.size();
    vector<int> ngl(n);

    for(int i = 0; i < n; i++){
        while(!s.empty() && v[s.top()] <= v[i]) s.pop();
        ngl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return ngl;
}

int main(){
    vector<int> v = {1,4,2,1,1,3,4,3,4,8};

    vector<int> ngr = NGR(v);
    vector<int> nsr = NSR(v);
    vector<int> nsl = NSL(v);
    vector<int> ngl = NGL(v);

    print(ngr);
    print(nsr);
    print(nsl);
    print(ngl);

    return 0;
}