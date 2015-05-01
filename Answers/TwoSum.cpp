
typedef struct hst {
	int data;
	int index;
}Hst;
void mergeSort(vector<Hst> &sqc, unsigned int bg, unsigned int ed);
int binarySearch(vector<Hst> &sqc, int item);
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<Hst> hst;
		Hst temp;
		int index1, index2, t;
		for(int i = 0; i < nums.size(); ++i) {
			temp.data = nums[i];
			temp.index = i;
			hst.push_back(temp);
		}
		mergeSort(hst, 0, nums.size()-1);
		for(int i = 0; i < nums.size(); ++i) {
			index2 = binarySearch(hst, target - hst[i].data);//find
			if(index2 != -1) {
				index2 = hst[index2].index;
				if(hst[i].index < index2) {
					return{ hst[i].index + 1, index2 + 1 };
				}
				return{ index2 + 1, hst[i].index + 1 };
			}
		}
	}
};
void mergeSort(vector<Hst> &sqc, unsigned int bg, unsigned int ed) {
	auto size = ed - bg + 1;
	if(size == 2 && sqc[bg].data > sqc[ed].data) {
		Hst temp;
		temp = sqc[bg];
		sqc[bg] = sqc[ed];
		sqc[ed] = temp;
	}
	else if(size > 2) {
		mergeSort(sqc, bg, bg + (ed - bg) / 2);
		mergeSort(sqc, bg + (ed - bg) / 2 + 1, ed);
		auto i = sqc.begin() + bg;
		auto mid = i + (ed - bg) / 2 + 1;
		auto j = mid;
		vector<Hst> temp;
		while(size--) {
			if(i != mid && (j != (sqc.begin() + ed + 1)) && i->data < j->data || (j == sqc.begin() + ed + 1)) {
				temp.push_back(*(i++));
			}
			else {
				temp.push_back(*(j++));
			}
		}
		for(auto i = sqc.begin() + bg; (i != sqc.begin() + ed + 1); ++i) {
			*i = temp[++size];
		}
	}
}
int binarySearch(vector<Hst> &sqc, int item) {
	auto bg = sqc.begin();
	auto ed = sqc.end();
	auto mid = bg + (ed - bg) / 2;
	if(item < bg->data || item > (ed - 1)->data) {
		return -1;
	}
	while(mid->data != item) {
		if(bg == mid) {
			return -1;
		}
		if(item < mid->data) {
			ed = mid - 1;
		}
		else {
			bg = mid + 1;
		}
		mid = bg + (ed - bg) / 2;
	}
	if(bg == mid && ed->data == mid->data) {
		mid = ed;
	}
	return (mid - sqc.begin());
}
//The answer is not good