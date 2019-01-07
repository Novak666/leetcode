#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        unsigned long long p;
        if(n<0) {
            p = -n;
            x = 1/x;
        }
        else
            p = n;
        double ans = 1;
        while(p){
            if(p & 1)
                ans *= x;
            x *= x;
            p >>= 1;
        }
        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
