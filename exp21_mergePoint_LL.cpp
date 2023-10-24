#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int length(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* findMergePoint(ListNode* headA, ListNode* headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(9);
    list2->next = list1->next->next; // Merge point

    ListNode* mergePoint = findMergePoint(list1, list2);
    
    if (mergePoint) {
        cout << "Merge point value: " << mergePoint->val << endl;
    } else {
        cout << "No merge point found." << endl;
    }
    while (list1) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
