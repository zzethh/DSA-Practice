int Solution::search(const vector<int> &A, int B) {

    // This commented portion contain solution where we find pivotal element first and then search

    // int n = A.size();

    // int l=0,r=n-1;



    // int midPoint = -1;

    // int minVal = 2e9;



    // while(l<=r){

    //     int mid = (l+r)>>1;

    //     if(A[mid]<=A[r]){

    //         if(A[mid]<minVal){

    //             midPoint = mid;

    //             minVal = A[mid];

    //         }

    //         r = mid-1;

    //     }

    //     else{

    //         l = mid+1;

    //     }

    // }



    // l=0,r=midPoint-1;

    // while(l<=r){

    //     int mid = (l+r)>>1;

    //     if(A[mid]==B) return mid;

    //     if(A[mid]<B) l = mid+1;

    //     else r = mid-1;

    // }



    // l=midPoint,r=n-1;

    // while(l<=r){

    //     int mid = (l+r)>>1;

    //     if(A[mid]==B) return mid;

    //     if(A[mid]<B) l = mid+1;

    //     else r = mid-1;

    // }



    // return -1;

    // Code Ends here









    // Below code where we don't require pivotal element anymore



    int n = A.size();

    int l = 0, r = n - 1;



    while (l <= r) {

        int mid = (l + r) >> 1;

        if (A[mid] == B) return mid;

        if (A[l] < A[r]) {

            if (A[mid] < B) l = mid + 1;

            else r = mid - 1;

        }

        else {

            if (A[mid] < B) {

                if ((B > A[r]) && (A[mid] > A[r])) l = mid + 1;

                else if ((B > A[r]) && (A[mid] < A[r])) r = mid - 1;

                else l = mid + 1;

            }

            else if (A[mid] > B) {

                if ((B < A[r]) && (A[mid] < A[r])) r = mid - 1;

                else if ((B < A[r]) && (A[mid] > A[r])) l = mid + 1;

                else r = mid - 1;

            }

        }

    }



    return -1;

}