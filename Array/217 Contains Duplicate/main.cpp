#include <iostream>

using namespace std;

static auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>visited;
        for(int i=0;i<nums.size();i++){
            if(visited.find(nums[i])==visited.end())
                visited.insert(nums[i]);
            else{
                return true;
            }
        }
        return false;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
