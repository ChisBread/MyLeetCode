class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> rtNode;
		vector<TreeNode*> q1, q2;
		if(root) {
			q1.push_back(root);
		}
		while(!(q1.empty() && q2.empty())) {// both empty?
			if(!q1.empty()) {
				rtNode.push_back(q1[q1.size()-1]->val);//push right value
				for(auto &i: q1) {//push leafNode to q2
					if(i->left) {
						q2.push_back(i->left);
					}
					if(i->right) {
						q2.push_back(i->right);
					}
				}
				q1.clear();
			}
			else if(!q2.empty()) {
				rtNode.push_back(q2[q2.size()-1]->val);//push right value
				for(auto &i : q2) {//push leafNode to q1
					if(i->left) {
						q1.push_back(i->left);
					}
					if(i->right) {
						q1.push_back(i->right);
					}
				}
				q2.clear();
			}
		}
		return rtNode;
	}
};
