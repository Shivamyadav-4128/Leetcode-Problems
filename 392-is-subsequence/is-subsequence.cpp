class Solution {
public:
   bool solve(int i, int j, string& s, string& t){
    if(i == s.size())
       return true;

       if(j == t.size())
         return false;

         if(s[i] == t[j])
            return solve(i + 1, j + 1, s, t);

            return solve(i, j + 1, s, t);
   }
    bool isSubsequence(string s, string t) {
        return solve(0,0,s,t);
        
    }
};