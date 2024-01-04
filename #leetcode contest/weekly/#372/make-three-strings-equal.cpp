class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < s1.length() and j < s2.length() and k < s3.length() and s1[i] == s2[j] and s2[j] == s3[k]) {
            i++;
            j++;
            k++;
        }
        if (i == 0) return -1;
        int cnt = 0;
        cnt += (s1.length() - i) + (s2.length() - j) + (s3.length() - j);
        return cnt;
    }
};