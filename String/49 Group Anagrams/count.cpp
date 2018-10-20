class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0){
            return result;
        }
        unordered_map<string, vector<string>> maps;
        for(int i = 0; i < strs.size(); i++){
            string key(26, '0');
            for(int j = 0; j < strs[i].size(); j++)
                key[strs[i][j] - 'a'] += 1;
            maps[key].push_back(strs[i]);
        }

        for (pair<string, vector<string>> a: maps){
            result.push_back(a.second);
        }
        return result;
    }
};
