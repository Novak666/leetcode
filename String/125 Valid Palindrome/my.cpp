#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> V;
        for(auto c : s){
            if(c >= 'a' && c <= 'z')
                V.push_back(c);
            else if(c >= 'A' && c <= 'Z')
                V.push_back(c - 'A' + 'a');
        }
        for(int i = 0; i < V.size(); i++)
            cout << V[i];
        for(int i = 0, j = V.size() - 1; i <= j; i++, j--){
            if(V[i] != V[j])
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "0P";
    Solution S;
    bool temp = S.isPalindrome(s);
    cout << S.isPalindrome(s);
    return 0;
}
