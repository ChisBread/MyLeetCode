class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int temp = 0;
		ListNode *H = new ListNode(0), *p;
		p = H;
		while(l1 || l2 || temp) {
			if(l1) {
				temp += l1->val;
				l1 = l1->next;
			}
			if(l2) {
				temp += l2->val;
				l2 = l2->next;
			}
			p = p->next = new ListNode(temp % 10);
			temp /= 10;
		}
		return H->next;
	}
};
