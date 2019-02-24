#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int table[n+1][m+1];
        for(int i = 0; i <= n; i++)
            table[i][1] = 1;
        for(int j = 0; j <= m; j++)
            table[1][j] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 2; j <= m; j++)
                table[i][j] = table[i][j-1] + table[i-1][j];
        return table[n][m];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
