vector<int> Solution::solve(vector<int> &A, int B) {

    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.begin() + B);
    for (int i = B; i < A.size(); i++) {
        int x = A[i];
        if (pq.top() < x) {
            pq.pop();
            pq.push(x);
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
