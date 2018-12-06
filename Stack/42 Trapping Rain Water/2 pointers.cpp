class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0, right_max = 0, sum = 0;
        int left = 0, right = height.size() - 1;
        //����ˮȡ����2�鵲�壬��ÿ���³��ֵ�һ������󵲰壬Ȼ������һ�������Ͻ���ˮ
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
