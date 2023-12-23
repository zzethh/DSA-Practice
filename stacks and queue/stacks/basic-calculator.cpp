class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push(sum);
                st.push(sign);
                sign = 1;
                sum = 0;
            }
            else if (s[i] == ')') {
                sum = st.top() * sum;
                st.pop();
                sum += st.top();
                st.pop();
            }
            else if (s[i] - '0' >= 0 and s[i] - '0' <= 9) {
                int num = 0;
                while (s.length() > i and s[i] >= '0' and s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                sum += num * sign;
                i--;
            }
        }
        return sum;
    }
};