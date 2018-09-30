class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0, k = 0, i = nums.size() - 1;
        while(j <= i){
            if(nums[j] < 1)
                swap(nums[j++], nums[k++]);
            else if(nums[j] > 1)
                swap(nums[j], nums[i--]);
            else
                j++;
        }
    }
};
