#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        vector<int> V;
        while(low <= high){
            mid = (low + high) / 2;
            if(!mid)
                if(nums[mid] == target){
                    V.push_back(0);
                    break;
                }
                else
                    low++;
            else if(nums[mid] == target && nums[mid] > nums[mid-1]){
                V.push_back(mid);
                break;
            }
            else if(nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(V.empty())
            return {-1, -1};
        low = mid, high = nums.size() - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(mid == nums.size() - 1)
                if(nums[mid] == target){
                    V.push_back(nums.size() - 1);
                    break;
                }
                else
                    high--;
            else if(nums[mid] == target && nums[mid] < nums[mid+1]){
                V.push_back(mid);
                break;
            }
            else if(nums[mid] == target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return V;
    }
};

int main()
{

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution S;
    S.searchRange(nums, target);
    cout << "Hello world!" << endl;
    return 0;
}
