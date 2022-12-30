int Solution::solve(string A) {
    unordered_set<char> s;
    for (auto x : A) {
        if (s.find(x) != s.end()) s.erase(x);
        else s.insert(x);
    }
    if (s.size() == 1 or s.empty()) return true;
    return false;
}
