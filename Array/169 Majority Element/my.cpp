#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> M;
        int i;
        for(i = 0; i < nums.size(); i++){
            if(M.count(nums[i]))
                M[nums[i]]++;
            else
                M[nums[i]] = 1;
            if(M[nums[i]] > nums.size() / 2)
                return nums[i];
        }
        return nums[i - 1];
    }
};

int main()
{
    vector<int> V = {3, 2, 3};
    Solution S;
    int n = S.majorityElement(V);
    cout << n << endl;
    return 0;
}
