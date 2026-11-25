class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> out_map;

        for(auto it :paths){
            string u = it[0];
            string v = it[1];

            out_map[u]++;
        }
        for(auto it : paths){
            string v = it[1];

            if(out_map[v] == 0)
              return v;
        }
        return "";
    }
};