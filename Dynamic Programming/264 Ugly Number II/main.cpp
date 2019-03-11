#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        int A[n] = {0};
        A[0] = 1;
        for(int i = 1; i < n; i++){
            A[i] = min(A[t2] * 2, min(A[t3] * 3, A[t5] * 5));
            if(A[i] == A[t2] * 2)
                t2++;
            if(A[i] == A[t3] * 3)
                t3++;
            if(A[i] == A[t5] * 5)
                t5++;
        }
        return A[n-1];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
