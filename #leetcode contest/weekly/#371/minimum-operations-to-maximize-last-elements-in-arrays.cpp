class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        int n = nums1.size();
        int maxi1 = nums1[n - 1];
        int maxi2 = nums2[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (nums1[i] <= maxi1 and nums2[i] <= maxi2) {
                continue;
            }
            else if (maxi1 >= nums2[i] and maxi2 >= nums1[i]) {
                cnt1++;
            }
            else {
                cnt1 = INT_MAX;
                break;
            }
        }
        swap(nums1[n - 1], nums2[n - 1]);
        swap(maxi1, maxi2);
        cnt2++;
        for (int i = 0; i < n - 1; i++) {
            if (nums1[i] <= maxi1 and nums2[i] <= maxi2) {
                continue;
            }
            else if (maxi1 >= nums2[i] and maxi2 >= nums1[i]) {
                cnt2++;
            }
            else {
                cnt2 = INT_MAX;
                break;
            }
        }
        int ans = min(cnt1, cnt2);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};