
class Solution {
public:
    void helper(vector<vector<int>> rooms, vector<bool> &v, int node) {
        if (v[node] == 1) return;

        v[node] = 1;

        for (auto nbr : rooms[node]) {
            if (v[nbr] != 1) {
                helper(rooms, v, nbr);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), 0);
        helper(rooms, visited, 0);
        for (auto x : visited) {
            if (x == 0) return false;
        }
        return true;
    }
};