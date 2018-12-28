#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size() || !nums2.size())
            return {};
        unordered_set<int> S(nums1.begin(), nums1.end());
        vector<int> V;
        for(auto c : nums2){
            if(S.count(c)){
                V.push_back(c);
                S.erase(c);
            }
        }
        return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
