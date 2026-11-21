class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        map<int, int> mp;
        for(int num : nums){

            if(mp[num] > 0)
             return num;

             mp[num]++;
            }
        return -1;
    }
};