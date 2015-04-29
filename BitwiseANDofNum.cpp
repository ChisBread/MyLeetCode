class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if(!(m && n)) {//(0 & x = 0)
			return 0;
		}
		unsigned int ans = 1 << 31;
		while(!((ans = ans >> 1) & n));//get biggest bit
		if(ans & m) {//is match?
			ans += rangeBitwiseAnd(m - ans, n - ans);//subbitsqc
		}
		else {//not match (0111 &to 1111 = 0)
			ans = 0;
		}
		return ans;
	}
};
//is it fast?
