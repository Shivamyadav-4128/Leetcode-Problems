class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

       map<int, int> mp;

       for(int num : nums){

        if(mp[num] > 0)
        return true;

        mp[num]++;
        }
        return false;
       } 
};