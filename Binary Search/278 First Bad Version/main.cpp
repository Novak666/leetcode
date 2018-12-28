#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(!isBadVersion(mid) && isBadVersion(mid + 1))
                return mid + 1;
            if(isBadVersion(mid))
                high = mid;
            else
                low = mid;
        }
        return low;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
