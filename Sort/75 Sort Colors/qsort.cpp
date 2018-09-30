#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return;
        qsort(nums, 0, nums.size() - 1);
    }
    void qsort(vector<int>& nums, int low, int high){
        if(low < high){
            int loc = partion(nums, low, high);
            qsort(nums, low, loc - 1);
            qsort(nums, loc + 1, high);
        }
    }
    int partion(vector<int>& nums, int low, int high){
        int temp = nums[low];
        while(low < high){
            while(low < high && nums[high] >= temp)
                high--;
            nums[low] = nums[high];
            while(low < high && nums[low] <= temp)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = temp;
        return low;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
