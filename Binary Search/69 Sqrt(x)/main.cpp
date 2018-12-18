#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid == x / mid) return mid; //³Ë¸Ä³ý
            else if(mid > x / mid) high = mid - 1;
            else low = mid + 1;
        }
        return low - 1;
    }
};

int main()
{
    int x = 8;
    Solution S;
    S.mySqrt(x);
    cout << INT_MAX << endl;
    return 0;
}
