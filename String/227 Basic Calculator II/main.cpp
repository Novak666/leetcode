#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> S;
        int num = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1){
                if(sign == '+')
                    S.push(num);
                if(sign == '-')
                    S.push(-num);
                if(sign == '*'){
                    int pre = S.top();
                    S.pop();
                    S.push(pre * num);
                }
                if(sign == '/'){
                    int pre = S.top();
                    S.pop();
                    S.push(pre / num);
                }
                num = 0;
                sign = s[i];
            }
        }
        int sum = 0;
        while(!S.empty()){
            sum += S.top();
            S.pop();
        }
        return sum;
    }
};
int main()
{
    string s = " 3+5 / 2 ";
    Solution S;
    cout << S.calculate(s) << endl;
    return 0;
}
