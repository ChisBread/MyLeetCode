class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> rtVal;
		vector<TreeNode*> q1, q2;
		if(root) {
			q1.push_back(root);
		}
		while(!(q1.empty() && q2.empty())) {// both empty?
			vector<TreeNode*> &father = q1.empty() ? q2 : q1;
			vector<TreeNode*> &son = q1.empty() ? q1 : q2;
			rtVal.push_back(pushSonNode(father, son));//push sunnode to son queue
		}
		return rtVal;
	}
	int pushSonNode(vector<TreeNode*> &father, vector<TreeNode*> &son) {//return (father) right value
		int val = father[father.size() - 1]->val;//push right value
		for(auto &i : father) {//push leafNode to q1
			if(i->left) {
				son.push_back(i->left);
			}
			if(i->right) {
				son.push_back(i->right);
			}
		}
		father.clear();
		return val;
	}
};
