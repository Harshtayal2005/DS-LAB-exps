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
void inOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	// left traversal
	inOrderTraversal(root->left);
    //Node printing
	cout<<root->data<<" ";
	//right order traversal
	inOrderTraversal(root->right);
}
int main(){
    Node* root = NULL; 
    root = buildTree(root);
    cout<<"in order traversal is: "<<endl;
    inOrderTraversal(root);
    return 0;
}