class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> heap(nums.begin(), nums.end());
        int product = 1;
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        return (first - 1) * (second - 1);
    }
};