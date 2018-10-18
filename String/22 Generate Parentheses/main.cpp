#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursion(res, "", n, 0);
        return res;
    }
    void recursion(vector<string> &res, string str, int left, int right){
        if(!left && !right)
            res.push_back(str);
        else{
            if(left > 0)
                recursion(res, str + "(", left - 1, right + 1);
            if(right > 0)
                recursion(res, str + ")", left, right - 1);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
