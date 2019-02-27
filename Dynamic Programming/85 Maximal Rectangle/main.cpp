#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<int> left(col, 0), right(col, col - 1), height(col, 0);
        int S = 0;
        for(int i = 0; i < row; i++){
            int curLeft = 0, curRight = col - 1;
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft); //一行的左端
                else{
                    curLeft = j + 1;
                    left[j] = 0;
                }
            for(int j = col - 1; j >= 0; j--)
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curRight); //一行的右端
                else{
                    curRight = j - 1;
                    right[j] = col - 1;
                }
            for(int j = 0; j < col; j++)
                S = max(S, (right[j] - left[j] + 1) * height[j]);
        }
        return S;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
