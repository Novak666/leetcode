#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = 0;
        int p = 0, sum = 0;
        int i = 0;
        for(; i < nums.size(); i++){
            sum += nums[i];
            if(sum >= s){
                while(sum - nums[p] >= s){ //漏了这种情况
                    sum -= nums[p];
                    p++;
                }
                len = i - p + 1;
                break;
            }
        }
        for(i++; i < nums.size(); i++){
            sum += nums[i];
            while(sum - nums[p] >= s){
                sum -= nums[p];
                p++;
            }
            int temp = i - p + 1;
            if(temp < len)
                len = temp;
        }
        return len;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
