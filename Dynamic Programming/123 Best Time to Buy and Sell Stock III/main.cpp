#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int fromLeft = 0, fromRight = n - 1;
        int minLeft = INT_MAX, maxRight = INT_MIN;
        int profit = 0, res = 0;
        int table[n] = {0};
        for(int i = 0; i < n; i++){
            if(prices[i] < minLeft)
                minLeft = prices[i];
            else
                profit = max(profit, prices[i] - minLeft);
            table[i] = profit;
        }
        res = table[n-1];
        profit = 0;
        for(int i = n - 1; i > 0; i--){
            if(prices[i] > maxRight)
                maxRight = prices[i];
            else
                profit = maxRight - prices[i];
            res = max(res, profit + table[i-1]);
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
