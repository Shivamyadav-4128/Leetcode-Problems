class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int l = i, r = i;

            // Odd length palindromes
            while(l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            // Even length palindromes
            while(l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};