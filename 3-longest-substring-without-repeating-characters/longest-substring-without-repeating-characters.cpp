class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, j = 0, ans = 0;

        map<char, int> mp;

        while(j < s.size()) {

            mp[s[j]]++;

            while(mp[s[j]] > 1){
                if(mp[s[j]] > 1){
                    mp[s[i]]--;
                }
                    else {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                ans = max(ans, j - i + 1);
                j++;
        }
        return ans;
    }
};