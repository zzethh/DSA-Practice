class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        vector<int> odd, oddt;
        vector<int> even, event;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even.push_back(nums[i]);
            }
            else odd.push_back(nums[i]);
            if (target[i] % 2 == 0) {
                event.push_back(target[i]);
            }
            else oddt.push_back(target[i]);
        }

        long long cnt = 0;
        for (int i = 0; i < even.size(); i++) {
            cnt += abs((long long)even[i] - (long long)event[i]) / 2;
        }
        for (int i = 0; i < odd.size(); i++) {
            cnt += abs((long long)odd[i] - (long long)oddt[i]) / 2;
        }
        return cnt / 2;

    }
};