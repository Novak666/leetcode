#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num[m][n];
        int i, j;
        num[0][0] = grid[0][0];
        for(i = 1; i < m; i++)
            num[i][0] = grid[i][0] + num[i-1][0];
        for(j = 1; j < n; j++)
            num[0][j] = grid[0][j] + num[0][j-1];
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
                num[i][j] = min(grid[i][j] + num[i][j-1], grid[i][j] + num[i-1][j]);

        return num[m-1][n-1];
    }
};

int main()
{
    vector<vector<int>> V = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution S;
    S.minPathSum(V);
    cout << "Hello world!" << endl;
    return 0;
}
