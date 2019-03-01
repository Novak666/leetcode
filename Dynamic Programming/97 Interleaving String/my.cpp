#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if((m + n) != k)
            return false;
        vector<vector<int>> A(m+1, vector<int>(n+1, 0));
        A[0][0] = 1;
        for(int i = 1; i <= k; i++){ //i为字符串s3的个数,j为字符串s1的个数
            for(int j = 0; j <= i && j <= m; j++){
                if((i-j-1) <= n && (i-j-1) >= 0 && A[j][i-j-1]){
                    if(s3[i-1] == s1[j]){
                        A[j+1][i-j-1] = 1;
                    }
                    if(s3[i-1] == s2[i-j-1]){
                        A[j][i-j] = 1;
                    }
                }
            }
        }
        return A[m][n] == 1;
    }
};

int main()
{
    Solution S;
    string s1 = "aacaac", s2 = "aacaaeaac", s3 = "aacaaeaaeaacaac";
    S.isInterleave(s1, s2, s3);
    cout << "Hello world!" << endl;
    return 0;
}
