class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, len = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                left++;
            else{
                if(left > right + 1)
                    right++;
                else if(left == right + 1){
                    right++;
                    len = ((left + right) > len) ? left + right : len;
                }
                else
                    left = right = 0;
            }
        }
        left = right = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ')')
                right++;
            else{
                if(right > left + 1)
                    left++;
                else if(right == left + 1){
                    left++;
                    len = ((left + right) > len) ? left + right : len;
                }
                else
                    left = right = 0;
            }
        }
        return len;
    }
};
