class Solution {
public:

    int customPows(int base, int exponent, int x) {
        int result = 1;
        for (int i = 0; i < exponent; ++i) {
            result = (result * base) % x; // Use modular multiplication to avoid overflow
        }
        return result;
    }

    //((aibi % 10)ci) % mi == target
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> v;
        for (int i = 0; i < variables.size(); i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            int result = customPows(a, b, 10);
            int x = customPows(result, c, m);
            if (x % m == target) {
                v.push_back(i);
            }
        }
        return v;
    }
};