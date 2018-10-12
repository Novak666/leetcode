#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int cout = 0, i = a.length() - 1, j = b.length() - 1;
        for(; i >= 0 && j >= 0; i--, j--){
            if(a[i] == '0' && b[j] == '0'){
                if(cout)
                    s += "1";
                else
                    s += "0";
                cout = 0;
            }
            else if(a[i] == '1' && b[j] == '1'){
                if(cout)
                    s += "1";
                else
                    s += "0";
                cout = 1;
            }
            else{
                if(cout)
                    s += "0";
                else
                    s += "1";
            }
        }
        if(i < 0){
            for(; j >= 0; j--){
                if(b[j] == '1'){
                    if(cout)
                        s += "0";
                    else
                        s += "1";
                }
                else{
                    if(cout)
                        s += "1";
                    else
                        s += "0";
                    cout = 0;
                }
            }
        }
        else{
            for(; i >= 0; i--){
                if(a[i] == '1'){
                    if(cout)
                        s += "0";
                    else
                        s += "1";
                }
                else{
                    if(cout)
                        s += "1";
                    else
                        s += "0";
                    cout = 0;
                }
            }
        }
        if(cout)
            s += "1";
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    string a = "100", b = "110010";
    Solution S;
    string out = S.addBinary(a, b);
    cout << out << endl;
    return 0;
}
