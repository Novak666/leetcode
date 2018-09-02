class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (nums[lo] + nums[hi] != target){
            while (nums[lo] + nums[hi] > target)
                --hi;
            while (nums[lo] + nums[hi] < target)
                ++lo;
        }
        return {lo+1, hi+1};
    }
};
