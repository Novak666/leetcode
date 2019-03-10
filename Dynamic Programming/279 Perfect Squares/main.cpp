#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            int temp = INT_MAX;
            for(int j = 1; (i - j * j) >= 0; j++)
                temp = min(temp, dp[i - j * j] + 1);
            dp[i] = temp;
        }
        return dp[n];
    }
};

int main()
{
    Solution S;
    S.numSquares(10);
    cout << "Hello world!" << endl;
    return 0;
}
