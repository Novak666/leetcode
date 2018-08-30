#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size())
            return 0;
        int i = 0, j;
        for(j = 0; j < nums.size(); j++)
            if(nums[j] != val)
                nums[i++] = nums[j];
        return i;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
