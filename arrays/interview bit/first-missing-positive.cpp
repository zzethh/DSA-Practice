class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        int missing = 1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == missing) {
                if (i < n - 1) {
                    if (A[i + 1] == missing) continue;
                }
                missing++;
            }
            else
            {
                if (A[i] > 0)
                    break;
            }
        }
        return missing;
    }
};