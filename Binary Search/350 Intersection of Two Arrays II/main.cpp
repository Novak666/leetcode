#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size() || !nums2.size())
            return {};
        vector<int> V;
        if(nums1.size() > nums2.size())
            find_intersect(V, nums2, nums1);
        else
            find_intersect(V, nums1, nums2);
        return V;

    }
    void find_intersect(vector<int>& V, vector<int>& small, vector<int>& big){
        unordered_map<int, int> M;
        for(auto c : small)
            M[c]++;
        for(auto c : big){
            if(M.count(c)){
                V.push_back(c);
                if(!--M[c])
                    M.erase(c);
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution S;
    S.intersect(nums1, nums2);
    cout << "Hello world!" << endl;
    return 0;
}
