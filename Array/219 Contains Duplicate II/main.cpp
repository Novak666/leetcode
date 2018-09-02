#include <iostream>

using namespace std;

static auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> S;
        for(int i = 0; i < nums.size(); i++){
            if(i > k)
                S.erase(nums[i - k - 1]);
            if(S.find(nums[i]) != S.end())
                return true;
            else
                S.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
