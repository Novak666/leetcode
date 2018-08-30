#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for(; i < nums.size(); i++)
            if(nums[i] < target)
                ;
            else
                return i;
        return i;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
