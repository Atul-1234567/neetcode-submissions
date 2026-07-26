
class Solution {
public:
struct Compare{
    bool operator()(ListNode* a,  ListNode* b){
        return a -> val > b -> val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , Compare >pq;

        for(auto node : lists){
            if(node != NULL){
             pq.push(node);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            tail -> next = temp;
            tail = tail -> next;

            if(temp -> next != NULL){
                pq.push(temp -> next);
            }
        }
       return dummy -> next;
    }
};
