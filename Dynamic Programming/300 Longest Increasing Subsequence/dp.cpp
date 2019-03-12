#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int dp[nums.size()] = {0};
        dp[0] = 1;
        int maxlen = 1;
        for(int i = 1; i < nums.size(); i++){
            int val = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    val = max(val, dp[j]);
            }
            dp[i] = val + 1;
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};

int main()
{
    Solution S;
    vector<int> V = {10,9,2,5,3,7,101,18};
    S.lengthOfLIS(V);
    cout << "Hello world!" << endl;
    return 0;
}
