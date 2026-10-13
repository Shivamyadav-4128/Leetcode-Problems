class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
          return a[1] > b[1];
        return a[0] < b[0];
      });

      vector<int> arr;
      for(auto& e : envelopes){
        arr.push_back(e[1]);
      }

      int n = arr.size();
      vector<int> lis;
      lis.push_back(arr[0]);

      for(int i = 1; i < n; i++){
        if(arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
      }
      return lis.size();
    }
};