auto x = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size())
            return 0;
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(nums[mid] > target)
            return mid;
        else
            return mid + 1;
    }
};
