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
void rigView(Node* root, vector<int>& ans, int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    //right
    rigView(root->right, ans, level+1);
    //left
    rigView(root->left, ans, level+1);
}
    vector<int> rightView(Node *root)
    {
    int level = 0;
    vector<int> ans;
    if(root==NULL){
    return ans;
   }
   rigView(root, ans, level);
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
    vector<int> ans = rightView(root);
    print(ans);
}
