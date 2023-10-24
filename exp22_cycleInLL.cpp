#include<iostream>
using namespace std;

struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* checkLoop(ListNode* head){
    
    ListNode *slow = head;
    ListNode *fast = head;
    while(slow!=NULL && fast!=NULL){
        
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
ListNode* getLoopNode(ListNode* head){
    if(head==NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* intersection = checkLoop(head);
    if(intersection==NULL){
        return NULL;
    }
    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
        
    }
    return slow;
}
ListNode *removeLoop(ListNode *head)
{
    if(head==NULL){
        return NULL;
    }
    ListNode* loopNode = getLoopNode(head);
    if(loopNode==NULL){
        return head;
    }
    ListNode* temp = loopNode;
    while(temp->next!=loopNode){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;

}
void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode* ans = checkLoop(head);
    if(ans!=NULL){
        cout<<"Loop is present at node of value: "<<ans->val<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }
    
}