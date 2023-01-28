int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for (auto x : A) {
        ans = ans ^ x;
    }
    return ans;
}
