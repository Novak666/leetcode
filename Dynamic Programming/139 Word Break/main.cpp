#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> S;
        S.insert(wordDict.begin(), wordDict.end());
        vector<bool> V(s.size() + 1, false);
        V[0] = true;
        for(int i = 1; i <= s.size(); i++)
            for(int j = i - 1; j >= 0; j--)
                if(V[j] && S.count(s.substr(j, i-j))){
                    V[i] = true;
                    break;
                }
        return V[s.size()];
    }
};


int main()
{
    Solution S;

    cout << "Hello world!" << endl;
    return 0;
}
