#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // f[k, ii] represents the max profit up until prices[ii] using at most k transactions.
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if (prices.size() <= 1) return 0;
        else if(prices.size() / 2 <= k)
            return quickSolve(prices);
        else {
            int maxProf = 0;
            vector<vector<int>> f(k+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= k; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii-1] - prices[ii]);
                }
            }
            return f[k][prices.size() - 1];
        }
    }
    private:
    int quickSolve(vector<int>& prices) {
        int len = prices.size(), profit = 0;
        for (int i = 1; i < len; i++)
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
