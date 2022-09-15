class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> v(prices);
        for (int i = 0; i < n; i++) {
            while (!st.empty() and prices[st.top()] >= prices[i]) {
                v[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};