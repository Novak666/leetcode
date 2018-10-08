#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> M = {
            {"+", [](int a, int b){return a + b;}},
            {"-", [](int a, int b){return a - b;}},
            {"*", [](int a, int b){return a * b;}},
            {"/", [](int a, int b){return a / b;}}
        };
        stack<int> S;
        for(auto s : tokens){
            if(!M.count(s))
                S.push(stoi(s));
            else{
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.push(M[s](a, b));
            }
        }
        return S.top();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
