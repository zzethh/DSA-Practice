class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> l;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mini = min(nums[i], mini);
            l.push_back(mini);
        }

        // for(int j=1;j<nums.size();j++){
        //     for(int k=j+1;k<nums.size();k++){
        //         if(nums[k]>l[j-1] and nums[k]<nums[j]) return true;
        //     }
        // }

        // return false;

        stack<int> st;
        for (int j = nums.size() - 1; j >= 1; j--) {
            while (!st.empty() and st.top() <= l[j - 1]) {
                st.pop();
            }
            if (!st.empty() and st.top() < nums[j]) return true;
            st.push(nums[j]);
        }

        return false;

    }
};