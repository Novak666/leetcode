#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int dp[n] = {0};
        //vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        return dp[n-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int cur = nums[0], pre = 0;
        for(int i = 1; i < n; i++){
            int tmp = max(cur, pre + nums[i]);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};

int main()
{
    Solution S;
    vector<int> V = {1, 2, 3, 1};
    S.rob(V);
    cout << "Hello world!" << endl;
    return 0;
}
