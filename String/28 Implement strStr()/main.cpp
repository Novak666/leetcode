#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int i = 0, j = 0, p;
        while(haystack.size() - i >= needle.size()){
            for(; i < haystack.size(); i++)
                if(haystack[i] != needle[0])
                    ;
                else
                    break;
            p = i;
            if(haystack.size() - i < needle.size())
                return -1;
            for(j = 0; j < needle.size(); j++, i++)
                if(haystack[i] != needle[j]){
                    i = p + 1;
                    break;
                }
            if(j == needle.size())
                return p;
        }
        return -1;
    }
};

int main()
{
    string s1 = "mississippi", s2 = "issip";
    Solution S;
    cout << S.strStr(s1, s2) << endl;
    return 0;
}
