class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        int wt;
        while (heap.size() > 1) {
            wt = heap.top();
            heap.pop();
            for (int i = 0; i < 1; i++) {
                if (!heap.empty()) {
                    wt = wt - heap.top();
                    heap.pop();
                    if (wt == 0) {
                        continue;
                    }
                    heap.push(wt);
                } else {
                    heap.push(wt);
                }
            }
        }
        if (heap.empty()) {
            return 0;
        } else {
            return heap.top();
        }
    }
};