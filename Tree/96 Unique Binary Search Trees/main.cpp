#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        //自下向上 DP算法
        vector<int> G(n + 1, 0);
        G[0] = G[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
                G[i] += G[j - 1] * G[i - j];

        return G[n];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
