#include <iostream>

using namespace std;
/*
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int cc = 0;
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int tmp = sum[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + cc;
                sum[i + j + 1] = tmp % 10 + '0';
                cc = tmp / 10;
            }
            sum[i] += cc;
        }
        int startpos = 0;
        for (;startpos < sum.size(); ++startpos)
        {
            if(sum[startpos] != '0')
                break;
        }
        if(startpos == sum.size())
            return "0";
        return sum.substr(startpos);
    }
};*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        for(int i = num1.size() - 1; i >= 0; i--){
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; j--){
                int temp = sum[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            sum[i] += carry;
        }
        size_t flag = sum.find_first_not_of("0");
        if(flag != string::npos)
            return sum.substr(flag);
        return "0";
    }
};

int main()
{
    string s1 = "15", s2 = "15";
    Solution S;
    S.multiply(s1, s2);
    cout << "Hello world!" << endl;
    return 0;
}
