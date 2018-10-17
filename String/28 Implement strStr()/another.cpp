class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int len = needle.length();
        if(haystack == "" || haystack.length() < len)
            return -1;
        for(int i = 0; i <= haystack.length()-len; i++){
            if(haystack.substr(i,len) == needle)
                return i;
        }
        return -1;
    }
};
