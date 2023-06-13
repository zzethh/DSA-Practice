class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while (i < s.length() and s[i] == 'a') {
            i++;
        }
        if (i == s.length()) i--;
        int j = i + 1;
        while (j < s.length() and s[j] != 'a') {
            j++;
        }
        cout << i << " " << j << endl;
        // string t=s.substr(i,j-i+1);
        // return t;
        for (int k = i; k < j; k++) {
            //cout<<s[k]<<".";
            if (s[k] == 'a') {
                s[k] = 'z';
                continue;
            }
            s[k] = s[k] - 1;
            //s[k]=(char)prev;
        }
        return s;
    }
};