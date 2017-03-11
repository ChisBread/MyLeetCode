/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListPtrLess {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, ListPtrLess> fuck;
       for(auto h: lists) {
           if(h) {
               fuck.push(h);
           }
       }
       ListNode *head = new ListNode(0), *ptr = head;
       while(!fuck.empty()) {
           ptr->next = fuck.top();
           ptr = ptr->next;
           fuck.pop();
           if(ptr->next) {
               fuck.push(ptr->next);
           }
       }
       ptr->next = nullptr;
       return head->next;
    }
};
