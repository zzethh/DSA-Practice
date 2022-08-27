class Solution {
public:
    int sumofdigits(int a) {
        int sum = 0;
        while (a != 0) {
            sum = sum + (a % 10);
            a = a / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size(); i++) {
            int temp = sumofdigits(nums[i]);
            m[temp].push_back(nums[i]);
        }

        int maxi = -1;
        for (auto x : m) {
            auto element = x.second;
            if (element.size() <= 1) {
                continue;
            }
            maxi = max(maxi, element[0] + element[1]);
        }
        return maxi;
    }

};