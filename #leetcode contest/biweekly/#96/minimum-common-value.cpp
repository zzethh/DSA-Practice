class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        while (nums1[i] != nums2[j] and i < nums1.size() and j < nums2.size()) {
            if (nums1[i] > nums2[j]) j++;
            else i++;
        }
        if (i == nums1.size() or j == nums2.size()) return -1;
        return nums1[i];
    }
};