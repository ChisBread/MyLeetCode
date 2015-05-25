class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        for(int i = 0; i < s.size(); ++i) {
            bool m[256] = {};
            for(int j = 0; !m[s[i+j]] && i+j < s.size(); ++j) {
                m[s[i+j]] = true;
                if(j + 1 > len) {
                    len = j + 1;
                }
            }
        }
        return len;
    }
};
