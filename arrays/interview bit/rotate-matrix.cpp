void reverse(vector<vector<int>> &m) {
    for (int i = 0; i < m.size(); i++) {
        int x = 0;
        int y = m[0].size() - 1;
        while (x < y) {
            swap(m[i][x], m[i][y]);
            x++;
            y--;
        }
    }
}

void transpose(vector<vector<int>> &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            if (i > j) {
                swap(m[i][j], m[j][i]);
            }
        }
    }
}

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    transpose(A);
    reverse(A);
    return;
}
