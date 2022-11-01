class Solution {
public:
    vector<int> helper(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                vector<int> result1 = helper(input.substr(0, i));
                vector<int> result2 = helper(input.substr(i + 1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }

        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};