#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
 vector <int> bottomView(Node *root) {
       vector<int> ans;
       if(root==NULL){
           return ans;
       }
       map<int, int> mapping;
       // hd and value
       queue<pair<Node*, int> > q;
       // root and hd
       q.push(make_pair(root, 0));
       while(!q.empty()){
           pair<Node*, int> temp = q.front();
           q.pop();
           Node* frontNode = temp.first;
           int hd = temp.second;
           mapping[hd] = frontNode->data;
           if(frontNode->left){
               q.push(make_pair(frontNode->left, hd-1));
           }
           if(frontNode->right){
               q.push(make_pair(frontNode->right, hd+1));
           }
       }
       for(auto ele: mapping){
           ans.push_back(ele.second);
       }
       return ans;
    }
void print(vector<int>& arr){
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = bottomView(root);
    print(ans);
}