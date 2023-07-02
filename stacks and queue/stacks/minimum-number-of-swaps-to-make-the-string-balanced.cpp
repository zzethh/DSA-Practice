class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        stack<char> st;
        for (auto x : s) {
            if (x == ']') {
                if (!st.empty() and st.top() == '[') {
                    st.pop();
                    continue;
                }
            }
            st.push(x);
        }
        double temp = (st.size() * 1.0) / 4;
        // cout<<temp;
        double ans = ceil(temp);
        // while(!st.empty()){
        //     cout<<st.top();
        //     st.pop();
        // }
        return ans;
    }
};