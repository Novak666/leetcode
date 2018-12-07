#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_max = 0, right_max = 0, left = 0, right = height.size() - 1;
        int sum = 0;
        while(left < right){
            if(height[left] < height[right]){
                int temp = (right - left) * height[left];
                temp > sum ? sum = temp : left++;
            }
            else{
                int temp = (right - left) * height[right];
                temp > sum ? sum = temp : right--;
            }
        }
        return sum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
