class Solution {
public:
    int fxn(string &sequence, string &word, string temp){
        if(sequence.find(temp) == string::npos)
         return 0;

         return 1 + fxn(sequence, word,temp + word);
    }

        int maxRepeating(string sequence, string word) {
        return fxn(sequence, word, word);
    }
};