class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        string curr = "";
        string ans = "";
        int i = 0;
        for (auto c : S) {
            if (c == '.') {
                if (i == 0) {
                    ans = curr + ans;
                }
                else ans = curr + '.' + ans;
                curr = "";
                i++;
                continue;
            }
            curr = curr + c;
        }
        ans = curr + '.' + ans;
        if (i == 0) return S;
        return ans;
    }
};