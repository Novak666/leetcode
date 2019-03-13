#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], res = nums[0];
        int maxNum = maxP, minNum = maxP;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0)
                swap(maxNum, minNum);
            maxNum = max(maxNum * nums[i], nums[i]);
            minNum = min(minNum * nums[i], nums[i]);
            res = max(res, maxNum);
        }
        return res;
    }
};

int main()
{
    vector<int> V = {2, 3, -2, 4};
    Solution S;
    S.maxProduct(V);
    cout << "Hello world!" << endl;
    return 0;
}
