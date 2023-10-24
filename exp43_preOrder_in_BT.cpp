#include<iostream>
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
void preOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
    //Node printing
	cout<<root->data<<" "; 
	// left traversal
	preOrderTraversal(root->left);
	//right order traversal
	preOrderTraversal(root->right);
}
int main(){
    Node* root = NULL; 
    root = buildTree(root);
    cout<<"pre order traversal is: "<<endl;
    preOrderTraversal(root);
    return 0;
}