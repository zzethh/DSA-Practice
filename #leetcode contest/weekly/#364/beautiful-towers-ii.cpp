typedef long long int ll;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
//         long long n=maxh.size();
//         long long maxi=0;
//         vector<long long> pref(n,0);
//         vector<long long> suff(n,0);
//         vector<long long> left(n,0);
//         vector<long long> right(n,0);
//         stack<int> st;
//         for(int i=0;i<maxh.size();i++){
//             while(!st.empty() and maxh[st.top()]>=maxh[i]){
//                 st.pop();
//             }
//             left[i]=st.empty()?-1:st.top();
//             st.push(i);
//         }
//         while (!st.empty()) st.pop();

//         for(int i=n-1;i>=0;i--){
//             while(!st.empty() and maxh[st.top()]>=maxh[i]){
//                 st.pop();
//             }
//             right[i]=st.empty()?n:st.top();
//             st.push(i);
//         }
//         for(int i=0;i<n;i++){
//             pref[i]=maxh[i];
//             if(i==0) continue;
//             if(maxh[i]>=maxh[i-1]){
//                 pref[i]+=pref[i-1];
//             }
//             else pref[i]+=(i-left[i]-1)*maxh[i]+(left[i]<0?0:pref[left[i]]);
//         }

//         for(int j=n-1;j>=0;j--){
//             suff[j]=maxh[j];
//             if(j==n-1) continue;
//             if(maxh[j]>=maxh[j+1]){
//                 suff[j]+=right[j+1];
//             }
//             else suff[j]+=(right[j]-j-1)*maxh[j]+(right[j]>=n?0:suff[right[j]]);
//         }

//         for(int j=0;j<n;j++){
//             maxi=max(maxi,suff[j]+pref[j]-maxh[j]);
//         }
//         return maxi;
        ll n = maxHeights.size();

        stack<int> s;
        vector<ll> prv(n, 0), nxt(n, 0);
        vector<ll> lft(n, 0), rgt(n, 0);

        for (int j = 0; j < n; j ++) {
            while (!s.empty() && maxHeights[s.top()] >= maxHeights[j])
                s.pop();

            prv[j] = s.empty() ? -1 : s.top();
            s.push(j);
        }

        while (!s.empty()) s.pop();

        for (int j = n - 1; j >= 0; j --) {
            while (!s.empty() && maxHeights[s.top()] >= maxHeights[j])
                s.pop();

            nxt[j] = s.empty() ? n : s.top();
            s.push(j);
        }

        for (ll j = 0; j < n; j ++) {
            lft[j] = maxHeights[j];

            if (j == 0) continue;

            if (maxHeights[j] >= maxHeights[j - 1])
                lft[j] += lft[j - 1];
            else
                lft[j] += (j - prv[j] - 1) * maxHeights[j] + (prv[j] < 0 ? 0 : lft[prv[j]]);
        }

        for (ll j = n - 1; j >= 0; j --) {
            rgt[j] = maxHeights[j];

            if (j == n - 1) continue;

            if (maxHeights[j] >= maxHeights[j + 1])
                rgt[j] += rgt[j + 1];
            else
                rgt[j] += (nxt[j] - j - 1) * maxHeights[j] + (nxt[j] >= n ? 0 : rgt[nxt[j]]);
        }

        ll ans = 0;
        for (int j = 0; j < n; j ++)
            ans = max(ans, lft[j] + rgt[j] - maxHeights[j]);

        return ans;
    }
};