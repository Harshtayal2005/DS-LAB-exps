#include<iostream>
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

int diameter(Node* root, int& ans){
    if(root==NULL){
        return 0;
    }
    int leftHeight = diameter(root->left, ans);
    int rightHeight = diameter(root->right, ans);
    ans = max(leftHeight + rightHeight + 1, ans);
    return (max(leftHeight, rightHeight) + 1);
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    int ans = 0;
    diameter(root, ans);
    cout<<"diameter of the tree is: "<<ans<<endl;
    return 0;
}