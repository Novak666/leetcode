#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        int low = 0, high = nums.size() - 1;
        if(nums[high] >= nums[low])
            return nums[0];
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] < nums[mid - 1])
                return nums[mid];
            if(nums[mid] >= nums[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
