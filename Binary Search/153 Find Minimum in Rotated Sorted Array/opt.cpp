class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};
