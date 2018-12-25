#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++; high--;
            }
            else if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
