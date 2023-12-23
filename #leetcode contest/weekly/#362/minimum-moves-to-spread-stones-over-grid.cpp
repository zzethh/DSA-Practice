class Solution {
public:
    vector<pair<int, int>> zero;
    vector<pair<int, int>> nonz;
    int result = INT_MAX;

    int distance(pair<int, int> x, pair<int, int> y) {
        return abs(x.first - y.first) + abs(x.second - y.second);
    }
    void arrange(vector<bool>&taken, vector<int> &order) {
        if (order.size() == zero.size()) {
            int val = 0;
            for (int j = 0; j < zero.size(); j++) {
                val += distance(nonz[order[j]], zero[j]);
            }
            result = min(result, val);
        }
        for (int i = 0; i < zero.size(); i++) {
            if (taken[i]) continue;
            taken[i] = true;
            order.push_back(i);
            arrange(taken, order);
            order.pop_back();
            taken[i] = false;
        }
    }

    int minimumMoves(vector<vector<int>>& grid) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != 0) {
                    for (int k = 0; k < grid[i][j] - 1; k++) {
                        nonz.push_back({i, j});
                    }
                }
                else zero.push_back({i, j});
            }
        }
        vector<bool> taken(zero.size(), false);
        vector<int> order;
        arrange(taken, order);
        return result;
    }
};