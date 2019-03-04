#include <iostream>

using namespace std;

class Solution {
public:
    void search(string& s, vector<int>& dp, int left, int right) {
      while (0 < left && right < s.length() && s[left] == s[right]) { // o(n^2)
        dp[right] = min(dp[right], dp[left - 1] + 1);
        --left;
        ++right;
      }
    }

    int minCut(string s) {
      s.insert(s.begin(), '1');

      vector<int> dp(s.length(), -1);
      for (int i = 1; i < s.length(); ++i) dp[i] = i - 1;

      for (int i = 1; i < s.length(); ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);

        search(s, dp, i - 1, i + 1);
        search(s, dp, i, i + 1);
      }
      return dp[s.length() - 1];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
