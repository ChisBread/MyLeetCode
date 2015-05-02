typedef struct index {
	int fir;
	int sec;
} Index;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int min = nums[0], max = nums[0];
		for(auto &i: nums) {//find max and min
			if(min > i) {
				min = i;
			}
			if(max < i) {
				max = i;
			}
		}
		Index *t = new Index[max - min + 1]();
		Index *table = &t[-min];
		for(int i = 0; i < nums.size(); ++i) {//build hash table
			if(!table[nums[i]].fir) {
				table[nums[i]].fir = i + 1;
			}
			else if(!table[nums[i]].sec) {
				table[nums[i]].sec = i + 1;
			}
		}
		for(int i = min; i <= max; ++i) {
			if(target - i >= min && target - i <= max && table[i].fir && table[target - i].fir) {
				if(table[i].fir < table[target - i].fir) {
					return{ table[i].fir, table[target - i].fir };
				}
				else if(table[i].fir == table[target - i].fir && table[target - i].sec) {
					return{ table[i].fir, table[target - i].sec };
				}
				else {
					return{ table[target - i].fir, table[i].fir };
				}
			}
		}
	}
};
