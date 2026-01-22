// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

ListNode* solve(ListNode* list1, ListNode* list2){
    ListNode* curr1 = list1;
    ListNode* next1 = curr1 -> next;
    ListNode* curr2 = list2; 
    ListNode* next2 = curr2 -> next;
    
    if(next1 == NULL){
        curr1 -> next = curr2;
        return list1;
    }

    while(next1 != NULL and curr2 != NULL){
        if((curr2 -> val >= curr1-> val) and (curr2 -> val <= next1 -> val)){
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL){
                curr1 -> next = curr2;
                return list1;
            }
        }
    }
    return list1;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1 -> val <= list2 -> val){
        return solve(list1,list2);
    }
    else return solve(list2,list1);
}

int main() {
    cout << "Test Case 1:" << endl;
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});
    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);
    ListNode* result1 = mergeTwoLists(l1, l2);
    cout << "Merged: "; printList(result1);
    cout << "-----------------" << endl;

    cout << "Test Case 2:" << endl;
    ListNode* l3 = createList({2});
    ListNode* l4 = createList({1});
    cout << "List 1: "; printList(l3);
    cout << "List 2: "; printList(l4);
    ListNode* result2 = mergeTwoLists(l3, l4);
    cout << "Merged: "; printList(result2);
    cout << "-----------------" << endl;

    cout << "Test Case 3 (Empty lists):" << endl;
    ListNode* l5 = createList({});
    ListNode* l6 = createList({});
    cout << "List 1: "; printList(l5);
    cout << "List 2: "; printList(l6);
    ListNode* result3 = mergeTwoLists(l5, l6);
    cout << "Merged: "; printList(result3);
    cout << "-----------------" << endl;

    cout << "Test Case 4 (One empty):" << endl;
    ListNode* l7 = createList({});
    ListNode* l8 = createList({0});
    cout << "List 1: "; printList(l7);
    cout << "List 2: "; printList(l8);
    ListNode* result4 = mergeTwoLists(l7, l8);
    cout << "Merged: "; printList(result4);

    return 0;
}