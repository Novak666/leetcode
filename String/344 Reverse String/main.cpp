#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
