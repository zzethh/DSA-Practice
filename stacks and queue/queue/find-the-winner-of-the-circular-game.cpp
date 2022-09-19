class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> d;
        for (int i = n; i >= 1; i--) {
            d.push_back(i);
        }

        while (d.size() != 1) {
            for (int i = 1; i < k; i++) {
                d.push_front(d.back());
                d.pop_back();
            }
            d.pop_back();
        }
        return d.back();
    }
};