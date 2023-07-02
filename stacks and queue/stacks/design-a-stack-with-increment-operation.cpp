class CustomStack {
public:
    vector<int> v;
    int top = -1;
    int n = 0;
    CustomStack(int maxSize) {
        v.resize(maxSize, -1);
        n = maxSize;
    }

    void push(int x) {
        if (top != n - 1) {
            top++;
            v[top] = x;
        }
    }

    int pop() {
        int ans = -1;
        if (top == -1) return -1;
        else {
            ans = v[top];
            v[top] = -1;
            top--;
        }
        return ans;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, n); i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */