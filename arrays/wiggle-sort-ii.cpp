class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();
        priority_queue<int>pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }

        int i = 1;

        while (!pq.empty() && i < n)
        {
            nums[i] = pq.top();
            pq.pop();
            i = i + 2;
        }

        int j = 0;

        while (!pq.empty() && j < n)
        {
            nums[j] = pq.top();
            pq.pop();
            j = j + 2;
        }
    }
};