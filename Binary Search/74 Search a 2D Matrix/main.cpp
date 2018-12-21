#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int rows = matrix.size();
        if(matrix[0].empty())
            return false;
        int cols = matrix[0].size();
        int low = 0, high = cols * rows - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(matrix[mid / cols][mid % cols] == target)
                return true;
            else if(matrix[mid / cols][mid % cols] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};

int main()
{
    int target = 2;
    vector<vector<int>> V;
    V.push_back({1, 1});
    Solution S;
    S.searchMatrix(V, target);
    cout << "Hello world!" << endl;
    return 0;
}
