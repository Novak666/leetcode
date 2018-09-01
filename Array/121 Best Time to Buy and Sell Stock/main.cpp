#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minprice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minprice)
                minprice = prices[i];
            else if(prices[i] - minprice > profit)
                profit = prices[i] - minprice;
        }
        return profit;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
