#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> V(numRows);
        for(int i = 0; i < numRows; i++){
            V[i].resize(i + 1, 1);
            for(int j = 1; j < i; j++)
                V[i][j] = V[i - 1][j - 1] + V[i - 1][j];
        }
        return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
