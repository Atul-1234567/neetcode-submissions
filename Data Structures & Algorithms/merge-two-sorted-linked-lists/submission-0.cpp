/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* temp = list1;
        ListNode* temp2 = list2;

        while(temp != NULL && temp2 != NULL){
            if(temp -> val <= temp2 -> val){
                tail -> next = temp;
                temp = temp -> next;
            }
             else if(temp -> val > temp2 -> val){
                tail -> next = temp2;
                temp2 = temp2 -> next;
            }
            tail = tail -> next;
        }
        if(temp != NULL) tail -> next = temp;
        if(temp2 != NULL)tail -> next = temp2;

        return dummy -> next;
    }
};
