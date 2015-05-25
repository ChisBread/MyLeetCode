class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		unsigned int temp(m^n), temp2(1 << 31), ans = 0;
		while(((temp2 = temp2 >> 1) > temp)) {//until first '!=bits'
			if(temp2 & n) {
				ans += temp2;
			}
		}
		return ans;
	}
};
