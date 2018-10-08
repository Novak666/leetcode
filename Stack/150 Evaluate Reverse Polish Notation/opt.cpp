class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> V = {"+", "-", "*", "/"};
        stack<int> S;
        for(auto s : tokens){
            if(find(V.begin(), V.end(), s) != V.end()){
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                if(s == "+") S.push(a + b);
                if(s == "-") S.push(a - b);
                if(s == "*") S.push(a * b);
                if(s == "/") S.push(a / b);
            }
            else
                S.push(stoi(s));
        }
        return S.top();
    }
};
