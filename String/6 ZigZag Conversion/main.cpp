#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        vector<string> V(numRows);
        int n = s.length();
        int row = 0, dir;
        for(int i = 0; i < n; i++){
            V[row].push_back(s[i]);
            if(row == 0)
                dir = 1;
            else if(row == numRows - 1)
                dir = -1;
            row = row + dir;
        }
        s.clear();
        for(int i = 0; i < numRows; i++)
            s.append(V[i]);
        return s;
    }
};

int main()
{
    string s = "AB";
    Solution S;
    string a = S.convert(s, 1);
    cout << a << endl;
    return 0;
}
