int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    vector<int> dx = { -1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = { -1, 0, 1, -1, 1, -1, 0, 1};
    int x1 = A[0];
    int y1 = B[0];
    int step = 0;
    for (int i = 1; i < A.size(); i++) {
        int x = abs(A[i] - x1);
        int y = abs(B[i] - y1);
        // if(x==y){
        //     float hypo=(sqrt(x*x+y*y))/(sqrt(2));
        //     step=step+ceil(hypo);
        // }
        step += max(x, y);
        x1 = A[i];
        y1 = B[i];
    }
    return step;
}