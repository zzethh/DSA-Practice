class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> temp;
        while (numOnes) {
            temp.push_back(1);
            numOnes--;
        }
        while (numZeros) {
            temp.push_back(0);
            numZeros--;
        }
        while (numNegOnes) {
            temp.push_back(-1);
            numNegOnes--;
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += temp[i];
        }
        return sum;
    }
};