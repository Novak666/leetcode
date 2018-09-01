#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> V(rowIndex + 1, 1);
        for(int n = 0; n < rowIndex + 1; n++)
            for(int i = 1, pre = 1; i < n; i++){
                int cur = V[i];
                V[i] = pre + cur;
                pre = cur;
            }
        return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
