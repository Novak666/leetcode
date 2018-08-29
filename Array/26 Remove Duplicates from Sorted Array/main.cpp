#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int i = 0, j;
        for(j = 0; j < nums.size(); j++){
            if(nums[j] != nums[i])
                nums[++i] = nums[j];
        }
        return ++i;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution S;
    int n = S.removeDuplicates(nums);
    for(int i = 0; i < n; i++)
        cout << nums[i] << endl;
    return 0;
}
