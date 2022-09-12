class MinStack {
public:
    int min;
    stack<vector<int>> st;
    MinStack() {

    }

    void push(int val) {
        if (!st.empty()) {
            if (val < st.top()[1]) {
                min = val;
            } else {
                min = st.top()[1];
            }
        }
        else {
            min = val;
        }
        st.push({val, min});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top()[0];
    }

    int getMin() {
        return st.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */