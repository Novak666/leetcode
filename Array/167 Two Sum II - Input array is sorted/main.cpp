#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> M;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(M.count(target - numbers[i]))
                if(M[target - numbers[i]] < i)
                    return{M[target - numbers[i]] + 1, i + 1};
                else
                    return{i + 1, M[target - numbers[i]] + 1};
            M[numbers[i]] = i;
        }
        return {};
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
