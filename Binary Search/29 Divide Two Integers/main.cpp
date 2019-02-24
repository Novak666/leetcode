#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int res = 0;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long long dividend1 = labs(dividend);
        long long divisor1 = labs(divisor);
        while(dividend1 >= divisor1){
            long long temp = divisor1, multiply = 1;
            while(dividend1 >= (temp << 1)){
                temp <<= 1;
                multiply <<= 1;
            }
            dividend1 -= temp;
            res += multiply;
        }
        return sign == -1 ? -res : res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
