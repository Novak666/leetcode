#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0){
            return result;
        }
        unordered_map<string, vector<string>> maps;
        for(int i = 0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            maps[temp].push_back(strs[i]);

        }

        for (pair<string, vector<string>> a: maps){
            result.push_back(a.second);
        }
        return result;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution S;
    S.groupAnagrams(strs);
    return 0;
}
