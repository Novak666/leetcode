#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        long long m = s.size(), n = t.size();
        long long table[n+1][m+1] = {0};
        for(long long j = 0; j <= m; j++)
            table[0][j] = 1;
        for(long long i = 0; i < n; i++)
            for(long long j = 0; j < m; j++)
                if(s[j] == t[i])
                    table[i+1][j+1] = table[i+1][j] + table[i][j]; //���е����Ѿ������ĺ���һ�е�
                else
                   table[i+1][j+1] = table[i+1][j];
        return table[n][m];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
