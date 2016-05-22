/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lo;    
        vector<TreeNode*> layer;
        if(root){
            layer.push_back(root);;
        }
        while(!layer.empty()){
            lo.push_back(vector<int>());
            for(auto &i:layer){
                lo.back().push_back(i->val);
            }
            
            vector<TreeNode*> stack;
            for(auto &i:layer){
                if(i->left) {
                    stack.push_back(i->left);
                }
                if(i->right) {
                    stack.push_back(i->right);
                }
            }
            layer = stack;
        }
        return lo;
    }
};
