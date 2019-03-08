#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        int cur1 = nums[0], pre = 0;
        for(int i = 1; i < n - 1; i++){
            int tmp = max(cur1, pre + nums[i]);
                pre = cur1;
                cur1 = tmp;
        }
        int cur2 = nums[1];
        pre = 0;
        for(int i = 2; i < n; i++){
            int tmp = max(cur2, pre + nums[i]);
                pre = cur2;
                cur2 = tmp;
        }
        return max(cur1, cur2);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
