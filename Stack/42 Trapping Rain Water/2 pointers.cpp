class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0, right_max = 0, sum = 0;
        int left = 0, right = height.size() - 1;
        //接雨水取决于2块挡板，而每次新出现的一定是最大挡板，然后在另一个方向上接雨水
        while(left < right){
            if(height[left] <= height[right]){
                height[left] >= left_max ? (left_max = height[left]) : sum += (left_max - height[left]);
                left++;
            }
            else{
                height[right] >= right_max ? (right_max = height[right]) : sum += (right_max - height[right]);
                right--;
            }
        }
        return sum;
    }
};
