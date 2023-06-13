class Solution {
public:
    int cou(int n) {
        int cnt = 0;
        while (n > 0) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
    int mini = INT_MAX;
    void helper(int n, int i, int cnt) {
        if (i == 20) return;
        if (n < 0) return;

        mini = min(mini, cnt + cou(n));
        helper(n + (1 << i), i + 1, cnt + 1);
        helper(n, i + 1, cnt);
    }
    int minOperations(int n) {
        // int mini=INT_MAX;
        // int num=n;
        // int k=n;
        // for(int i=0;i<15;i++){
        //     n=k+(1<<i);
        //     num=k-(1<<i);
        //     cout<<n<<" "<<num<<endl;
        //     if(num>=0){
        //         mini=min(mini,min(cou(n),cou(num)));
        //     }
        //     else mini=min(mini,cou(n));
        // }
        // return mini+1;
        helper(n, 0, 0);
        return mini;
    }
};