#include<iostream>
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
bool searchInBST(Node *root, int x) {
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    else if(x < root->data){
        // search in left
        return searchInBST(root->left, x);
    }
    else{
        return searchInBST(root->right, x);
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data: "<<endl;
    takeInput(root);
    bool ans = searchInBST(root, 3);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    return 0;
}
