#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int begin = 0, end = 0, i;
        for(i = 0; i < nums.size(); i++)
            if(nums[i] == 0){
                begin = end = i;
                break;
            }
        for(i++; i < nums.size(); i++){
            if(nums[i] == 0)
                end = i;
            else{
                swap(nums[i], nums[begin]);
                begin++;
                end++;
            }
        }
    }
};

int main()
{
    vector<int> nums = {1, 0, 1};
    Solution S;
    S.moveZeroes(nums);

    cout << "Hello world!" << endl;
    return 0;
}
