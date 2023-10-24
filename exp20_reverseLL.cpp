#include<iostream>
using namespace std;

struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode* head){
    if(head->next == NULL) return head;
    
    ListNode* newHead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead; 
}
int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    //print(head);
    ListNode *revHead = reverse(head);
    print(revHead);
}