class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> S;
        for(int num : nums){
            if(S.count(num))
                return num;
            S.insert(num);
        }
    }
};
