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
 struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    }
};
class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto l : lists){
            if(l!= nullptr){
                pq.push(l);
            }
        }
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            curr->next=node;
            curr=curr->next;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};