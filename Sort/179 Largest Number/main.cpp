#include <iostream>

using namespace std;

class Solution {
public:
    static bool cmp(string a, string b){
        return a + b > b + a;
    }
string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i < nums.size(); i++) ans.push_back(to_string(nums[i]));
        sort(ans.begin(), ans.end(), cmp);
        string res;
        for(int i = 0; i < nums.size();i++) res += ans[i];
        if(res[0] == '0') res = "0";
    return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
