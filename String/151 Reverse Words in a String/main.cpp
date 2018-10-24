#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if(s == "")
            return;
        s.insert(s.begin(), ' ');
        s.insert(s.end(), ' ');
        string::iterator i = s.begin();
        string::iterator j = s.begin();
        reverse(s.begin(), s.end());
        for(; j != s.end();){
            while(j != s.end() && *j == ' ')
                j++;
            i = j = s.erase(i, j - 1) + 1;
            while(j != s.end() && *j != ' ')
                j++;
            reverse(i, j);
            i = j;
        }
        if(s == " "){
            s = "";
            return;
        }
        s.erase(s.begin(), s.begin() + 1);
        s.erase(s.end() - 1, s.end());
    }
};

int main()
{
    string s = "";
    Solution S;
    S.reverseWords(s);
    s.erase(s.end() - 1, s.end());
    cout << s << endl;
    return 0;
}
