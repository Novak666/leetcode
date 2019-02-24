#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int num[n];
        num[0] = 1;
        num[1] = 2;
        for(int i = 2; i <= (n - 1); i++)
            num[i] = num[i-1] + num[i-2];
        return num[n-1];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
