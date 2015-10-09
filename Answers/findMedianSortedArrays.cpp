class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = nums1.size() + nums2.size();
		if(len & 0x1) {
			return findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), len / 2 + 1);
		}
		else {
			return (findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), len / 2)
				+ findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), len / 2 + 1))/2;
		}
	}
	double findKth(
		vector<int>::iterator minIter, int minLen,
		vector<int>::iterator iter, int len, int k) {
		if(minLen > len) {
			return findKth(iter, len, minIter, minLen, k);
		}
		if(minLen == 0) {
			return iter[k - 1];
		}
		if(k == 1) {
			return *iter > *minIter ? *minIter : *iter;
		}
		int minPart = minLen>k / 2 ? k / 2 : minLen;
		int maxPart = k - minPart;
		if(minIter[minPart - 1] > iter[maxPart - 1]) {
			return findKth(minIter, minLen, iter + maxPart, len - maxPart, k - maxPart);
		}
		else if(minIter[minPart - 1] < iter[maxPart - 1]) {
			return findKth(minIter + minPart, minLen - minPart, iter, len, k - minPart);
		}
		else {
			return minIter[minPart - 1];
		}
	}
};
