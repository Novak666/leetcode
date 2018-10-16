#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if(!strs.size())
            return s;
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(int j = 0; j < strs.size(); j++)
                if(i > strs[j].size() - 1 || c != strs[j][i])
                    return s;
            s += c;
        }
        return s;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
