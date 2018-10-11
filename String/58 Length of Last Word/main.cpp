#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, out = 0;
        for(char x : s){
            if(x != ' '){
                count++;
                out = count;
            }
            else{
                if(count)
                    out = count;
                count = 0;
            }
        }
        return out;
    }
};

int main()
{
    string s = "a";
    Solution S;
    int temp = S.lengthOfLastWord(s);
    cout << temp << endl;
    return 0;
}
