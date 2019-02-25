#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> result(triangle.back());
        for(int layer = row - 2; layer >= 0; layer--)
            for(int i = 0; i <= layer; i++)
                result[i] = min(result[i], result[i+1]) + triangle[layer][i];
        return result[0];
    }
};

int main()
{
    cout << V.back() << endl;
    return 0;
}
