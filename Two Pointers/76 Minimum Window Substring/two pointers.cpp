class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> V(256, 0);
        for(auto c : t)
            V[c]++;
        int min_len = INT_MAX, begin = 0, end = 0;
        int contain_num = 0;
        string res;
        for(; end < s.size(); end++){
            if(--V[s[end]] >= 0)  //update end
                contain_num++;
            while(contain_num == t.size()){
                if(end - begin + 1 < min_len){ //update res
                    min_len = end - begin + 1;
                    res = s.substr(begin, min_len);
                }
                if(++V[s[begin]] > 0) //update begin
                    contain_num--;
                begin++;
            }
        }
        return res;
    }
};
