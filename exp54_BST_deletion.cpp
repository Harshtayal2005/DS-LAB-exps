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
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root, int val){
    // assuming that val is definitely present in one of the node data of BST
    if(root==NULL)
    return root;
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int maxi = maxVal(root->left)->data;
            root->data = maxi;
            root->left = deleteFromBST(root->left, maxi);
            return root;
            // or
            // int mini = minVal(root->right)->data;
            // root->data = mini;
            // root->right = deleteFromBST(root->right, mini);
            // return root;
        }
   

    }
    else if(root->data > val){
        //left
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        //right
        root->right =  deleteFromBST(root->right, val);
        return root;
    }
    
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data: "<<endl;
    takeInput(root);
    deleteFromBST(root, 3);
    return 0;
}