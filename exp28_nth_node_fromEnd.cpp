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

ListNode* findNthFromEnd(ListNode* head, int n) {
    if (!head || n <= 0) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    for (int i = 0; i < n; i++) {
        if (!fast) {
            return nullptr; 
        }
        fast = fast->next;
    }

    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


int main(){
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    //int n; cin>>n;

    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    ListNode* ans = findNthFromEnd(head, 2);

    cout<< ans->val <<endl;

    return 0;
}