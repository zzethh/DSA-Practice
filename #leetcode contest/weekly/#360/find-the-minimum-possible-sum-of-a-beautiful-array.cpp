class Solution {
public:
    //int mod=1e9+7;
    int minimumPossibleSum(int n, int k) {
//         unordered_set<int> s;
//         long long sum=0;
//         for(int i=1;s.size()<n;i++){
//             int x=(target-i);
//             if(s.find(x)==s.end()){
//                 sum+=i;
//                 s.insert(i);
//             }
//         }

//         return sum;

        long long sum = 0, num = 1;
        for (long long i = 0; i < n; i++) {
            if (num >= k) {
                sum += num++;
            }
            else if (k - num < num) {
                num++, i--;
            }
            else {
                sum += num++;
            }
        }
        return sum % 1000000007;

    }
};