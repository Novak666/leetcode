#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return vector<string>();
        vector<string> V({""});
        string phone[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); i++){
            string s = phone[digits[i] - '2'];
            vector<string> temp;
            for(int j = 0; j < V.size(); j++)
                for(int k = 0; k < s.size(); k++)
                    temp.push_back(V[j] + s[k]);
            V.swap(temp);
        }
        return V;
    }
};

int main()
{
    string s = "23";
    Solution S;
    S.letterCombinations(s);
    cout << "Hello world!" << endl;
    return 0;
}
