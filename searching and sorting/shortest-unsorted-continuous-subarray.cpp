class Solution {
public:
    bool outofOrder(vector<int> arr, int i) {
        int x = arr[i];
        if (i == 0) {
            return x > arr[1];
        }
        if (i == arr.size() - 1) {
            return x < arr[i - 1];
        }
        return x > arr[i + 1] or x < arr[i - 1];
    }

    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (outofOrder(nums, i)) {
                smallest = min(smallest, x);
                largest = max(largest, x);
            }
        }

        if (smallest == INT_MAX) {
            return 0;
        }

        int left = 0;
        while (smallest >= nums[left]) {
            left++;
        }
        int right = nums.size() - 1;
        while (largest <= nums[right]) {
            right--;
        }

        return right - left + 1;
    }
};