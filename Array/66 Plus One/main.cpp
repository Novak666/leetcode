#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] < 9){
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> V(digits.size() + 1, 0);
        V[0] = 1;
        return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
