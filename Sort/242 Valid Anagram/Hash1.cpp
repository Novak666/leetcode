class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> M;
        for(int i = 0; i < s.length(); i++){
            M[s[i]]++;
            M[t[i]]--;
        }
        for(auto m : M)
            if(m.second)
                return false;
        return true;
    }
};
