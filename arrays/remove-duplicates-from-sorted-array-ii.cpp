class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int prev = 0;
		for (int curr = 0; curr < nums.size(); curr++) {
			if (prev == 0 or prev == 1 or nums[prev - 2] != nums[curr]) {
				nums[prev] = nums[curr];
				prev++;
			}
		}
		return prev;
	}

};