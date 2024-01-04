class tree {
public:
	vector<int> seg;
	tree(int n) {
		seg.resize(4 * n + 1);
	}
	//O(n)
	void build(int ind, int low, int high, vector<int> &arr) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
	//O(logn)
	int query(int ind, int low, int high, int l, int r) {
		//no overlap
		if (r < low or high < l) return INT_MIN;
		//complete overlap
		if (low >= l and high <= r) return seg[ind];

		int mid = (low + high) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return max(left, right);
	}
};

class Solution {
public:
	vector<int> leftmostBuildingQueries(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		vector<int> result;
		tree t(n);
		t.build(0, 0, n - 1, nums);
		for (auto it : queries) {
			int a = it[0];
			int b = it[1];
			if (a > b) swap(a, b);
			if (a == b or nums[a] < nums[b]) {
				result.push_back(b);
				continue;
			}
			int x = max(nums[a], nums[b]) + 1;
			int l = b, r = n - 1;
			while (l < r) {
				int mid = (l + r) / 2;
				int maxleft = t.query(0, 0, n - 1, l, mid);
				if (maxleft >= x) {
					r = mid;
				}
				else l = mid + 1;
			}
			result.push_back((nums[l] < x) ? -1 : l);
		}
		return result;
	}
};