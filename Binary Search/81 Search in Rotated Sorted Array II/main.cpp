#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, mid;
        while(begin <= end){
            mid = (begin + end) / 2;
            if(nums[mid] == target) return true;
            if(nums[begin] == nums[mid] && nums[end] == nums[mid]){
                begin++; end--;
            }
            else if(nums[begin] <= nums[mid]) //是不是有序
                if(target >= nums[begin] && target <= nums[mid])
                    end = mid - 1;
                else
                    begin = mid + 1;
            else{
                if(target >= nums[mid + 1] && target <= nums[end])
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
