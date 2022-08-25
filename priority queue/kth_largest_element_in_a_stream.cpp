#include<bits/stdc++.h>
using namespace std;


class KthLargest {
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    KthLargest(int k, vector<int>& nums) {
        if (nums.size() >= k) {
            for (int i = 0; i < k; i++) {
                heap.push(nums[i]);
            }
            for (int i = k; i < nums.size(); i++) {
                if (heap.top() < nums[i]) {
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                heap.push(nums[i]);
            }
            for (int i = 0; i < k - nums.size(); i++) {
                heap.push(INT_MIN);
            }
        }

    }

    int add(int val) {
        if (heap.top() < val) {
            heap.pop();
            heap.push(val);
        }
        while (heap.empty() > 1) {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main() {



    return 0;
}

