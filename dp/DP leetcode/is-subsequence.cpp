class Solution {
public:

    // bool helper(string s,string t,int i,int j){

    // }

    bool isSubsequence(string s, string t) {
        // int i=0,j=0;
        // return helper(s,t,i,j);
        int i = 0, j = 0;
        while (i < s.length() and j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else j++;
        }
        if (i == s.length()) return true;

        return false;
    }
};