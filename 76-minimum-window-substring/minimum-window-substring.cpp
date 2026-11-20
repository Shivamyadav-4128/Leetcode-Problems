class Solution {
public:
    string minWindow(string s, string t) {


        map<char, int> mp;

        for(int i = 0; i <t.size(); i++){
            mp[t[i]]++;
        }
        int i = 0, j = 0;
        int count = t.size();
        int start = 0, len = INT_MAX;


        while(j < s.size()){
            if(mp[s[j]] > 0){
            count--;
        }
        mp[s[j]]--;

            while(count == 0) {
                if(j - i + 1 < len){
                    len = j - i + 1;
                    start = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    count++;
                }
                i++;
            }
            j++;
        }
        if(len == INT_MAX){
            return "";
        }
        return s.substr(start, len);

    }
};