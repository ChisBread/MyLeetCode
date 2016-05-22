class Solution {
public:
    vector<string> generateParenthesis(int n) {
           vector<string> ret;
           solu(ret, "(", 1, n);
           return ret;
    }
    void solu(vector<string> &ret, string ans, int l, int n) {
        if(l == n) {
            for(int i = 0; i < n; ++i){
                ans.push_back(')');
            }
            ret.push_back(ans);
            return;
        }
        ans.push_back('(');
        solu(ret, ans, l+1, n);
        if(l) {
            ans.back() = ')';
            solu(ret, ans, l-1, n-1);
        }
    }
};
