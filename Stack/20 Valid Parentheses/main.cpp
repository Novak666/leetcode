#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(auto c : s){
            if(c == '(')
                S.push(')');
            else if(c == '[')
                S.push(']');
            else if(c == '{')
                S.push('}');
            else if(S.empty() || S.top() != c)
                return false;
            else
                S.pop();
        }
        return S.empty();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
