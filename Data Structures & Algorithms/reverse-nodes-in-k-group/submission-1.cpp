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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Check if k nodes exist
        while (cnt < k) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // Reverse remaining list first
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reverse current group of k nodes
        temp = head;
        cnt = 0;

        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};