#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), max1;
        int sum[n];
        max1 = sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            sum[i] = max(nums[i], nums[i] + sum[i - 1]);
            max1 = max(max1, sum[i]);
        }
        return max1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
