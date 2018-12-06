#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        for(int i = 0; i < n; i++){
            int max_left = 0, max_right = 0;
            for(int j = 0; j < i; j++)
                max_left = max(max_left, height[j]);
            for(int k = i + 1; k < n; k++)
                max_right = max(max_right, height[k]);
            int temp = min(max_left, max_right) - height[i];
            if(temp > 0)
                sum += temp;
        }
        return sum;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution S;
    S.trap(height);
    cout << "Hello world!" << endl;
    return 0;
}
