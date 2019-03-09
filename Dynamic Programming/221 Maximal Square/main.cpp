#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        int maxlen = 0;
        for(int i = 1; i <= rows; i++)
            for(int j = 1; j <= cols; j++)
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    maxlen = max(maxlen, dp[i][j]);
                }
        return maxlen * maxlen;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
