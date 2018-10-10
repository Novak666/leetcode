#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int start = 0, len = 1;
        for(int i = 0; i < s.size() && (s.size() - i > len /2); i++){
            int begin = i, end = i;
            while(end < s.size() - 1 && s[end] == s[end + 1]){
                end++;
                i++;
            }
            while(begin > 0 && end < s.size() - 1 && s[begin - 1] == s[end + 1]){
                begin--;
                end++;
            }
            int newlen = end - begin + 1;
            if(newlen > len){
                start = begin;
                len = newlen;
            }
        }
        return s.substr(start, len);
    }
};

int main()
{
    string s = "aaabaaaa";
    string s1 = longestPalindrome(s);
    cout << s1 << endl;
    return 0;
}
