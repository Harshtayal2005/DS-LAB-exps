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
void postOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	// left traversal
	postOrderTraversal(root->left);
	//right order traversal
	postOrderTraversal(root->right);
    //Node printing
	cout<<root->data<<" "; 
}
int main(){
    Node* root = NULL; 
    root = buildTree(root);
    cout<<"post order traversal is: "<<endl;
    postOrderTraversal(root);
    return 0;
}