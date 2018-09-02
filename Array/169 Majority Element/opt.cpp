class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == major)
                count++;
            else if(!count){
                major = nums[i];
                count++;
            }
            else
                count--;
        }
        return major;
    }
};
