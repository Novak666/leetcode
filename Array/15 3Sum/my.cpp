#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int fast = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                int sum = -nums[i], j = i + 1, k = nums.size() - 1;
                while(j < k){
                    if(nums[j] + nums[k] == sum){
                        res.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j + 1]) j++;
                        while(j < k && nums[k] == nums[k - 1]) k--;
                        j++; k--;
                    }
                    else if(nums[j] + nums[k] < sum)
                        j++;
                    else
                        k--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    Solution S;
    res = S.threeSum(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
