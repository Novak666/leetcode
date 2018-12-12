#include <iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])
                return nums[i];
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
