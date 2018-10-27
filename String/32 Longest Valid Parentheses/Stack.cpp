#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> S;
        S.push(-1);
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                S.push(i);
            else{
                S.pop();
                if(S.empty())
                    S.push(i);
                if((i - S.top()) > len)
                    len = i - S.top();
            }
        }
        return len;
    }
};

int main()
{
    string s = ")()())";
    Solution S;
    cout << S.longestValidParentheses(s);
    return 0;
}
