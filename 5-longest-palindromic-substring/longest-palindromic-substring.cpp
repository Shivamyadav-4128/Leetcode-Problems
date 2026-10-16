class Solution {
public:
int fxn(int i, int j, string &s) {
    if(i >= j) return true;

    if(s[i] != s[j]) return false;

    return fxn(i + 1, j - 1, s);
}
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxi = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(fxn(i , j, s) && j - i + 1 > maxi){
                    maxi = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxi);
    }
};