class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<int> ans;

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            indegree[v]++;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
            }
        }
            return ans;
    }
};