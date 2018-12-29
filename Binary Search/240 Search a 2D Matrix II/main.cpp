#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = 0;
        if (rows > 0)
            cols = matrix[0].size();
        int i = 0;
        int j = cols - 1;
        while(i<rows && j>=0)
        {
            if (target == matrix[i][j])
                return true;
            if (target < matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
