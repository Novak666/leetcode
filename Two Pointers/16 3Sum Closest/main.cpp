#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) //ÀàËÆÓÚ3 sum
            return 0;
        int min = INT_MAX; //·¸´íÁË
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int temp  = target - nums[i];
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                if(temp - nums[j] - nums[k] == 0)
                    return target;
                else if(temp - nums[j] - nums[k] > 0){
                    if(abs(min) > abs(temp - nums[j] - nums[k]))
                        min = temp - nums[j] - nums[k];
                    j++;
                }
                else{
                    if(abs(min) > abs(temp - nums[j] - nums[k]))
                        min = temp - nums[j] - nums[k];
                    k--;
                }
            }
        }
        return target - min;
    }
};

int main()
{
    vector<int> nums = {-1, 2, 1, 4};
    Solution S;
    S.threeSumClosest(nums, 1);
    cout << "Hello world!" << endl;
    return 0;
}
