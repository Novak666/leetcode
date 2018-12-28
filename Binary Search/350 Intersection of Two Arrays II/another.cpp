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
                if(--M[c] >= 0)
                    V.push_back(c);
            }
        }
    }
};
