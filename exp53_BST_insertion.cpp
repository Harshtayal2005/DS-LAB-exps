#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* &root, int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    if(val<root->data){
        //left call
        root->left = insertToBST(root->left, val);
    }
    else{
        root->right = insertToBST(root->right, val);
    }
    return root;

}
void takeInput(Node* &root){
    int d;
    cin>>d;
    while(d!=-1){
        insertToBST(root, d);
        cin>>d;
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data: "<<endl;
    takeInput(root);
    return 0;
}