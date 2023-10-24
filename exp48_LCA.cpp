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
Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL){
           return NULL;
       }
       if(root->data==n1 || root->data==n2){
           return root;
       }
       
       Node* leftAns = lca(root->left, n1, n2);
       Node* rightAns = lca(root->right, n1, n2);
       if(leftAns!=NULL && rightAns!=NULL){
           return root;
       }
       else if(leftAns!=NULL && rightAns==NULL){
           return leftAns;
       }
       else if(rightAns!=NULL && leftAns==NULL){
           return rightAns;
       }
       else{
           return NULL;
       }
    }
int main(){
    Node* root = NULL;
    root = buildTree(root);
    Node* ans = lca(root, 6, 3);
    if(ans!=NULL){
        cout<<"Ancestor node value is: "<<ans->data<<endl;
    }
    else{
        cout<<"doesn't exist"<<endl;
    }
    return 0;
}