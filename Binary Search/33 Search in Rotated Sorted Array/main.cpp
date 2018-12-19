#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //任意拆分，其中一半肯定有序
        int begin = 0, end = nums.size() - 1, mid;
        while(begin <= end){
            mid = (begin + end) / 2;
            if(nums[mid] == target) return mid;
            if(nums[begin] <= nums[mid])
                if(target >= nums[begin] && target <= nums[mid])
                    end = mid - 1;
                else
                    begin = mid + 1;
            else{
                if(target >= nums[mid] && target <= nums[end])
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
