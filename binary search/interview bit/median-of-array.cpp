double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (B.size() < A.size()) return findMedianSortedArrays(B, A);
    int n1 = A.size();
    int n2 = B.size();
    int low = 0, high = n1;
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : A[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : B[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : A[cut1];
        int right2 = cut2 == n2 ? INT_MAX : B[cut2];

        if (left1 <= right2 and left2 <= right1) {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2) {
            high = cut1 - 1;
        }
        else low = cut1 + 1;
    }
    return 0.0;
}
