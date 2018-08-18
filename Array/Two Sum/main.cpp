#include <iostream>
#include <vector>
#include <unordered_map >

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(M.count(target - nums[i]))
                return{M[target - nums[i]], i};
            M[nums[i]] = i;
        }
        return {};
    }
};


int main()
{
    Solution S;
    vector<int> V{2, 7, 11, 15};
    //V[0] = 2;
    //V[1] = 7;
    //V[2] = 11;
    //V[3] = 15;
    int target = 22;
    vector<int> res = S.twoSum(V, target);
    cout << res[0] << endl;
    cout << res[1] << endl;
}
