#include <iostream>

using namespace std;
//太繁琐了,不可能在短时间内写完
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string s1, s2;
        int flag = 0, num1, num2, cflag1 = 0, cflag2 = 0;
        for(int i = 0, j = 0; i <= version1.size() - 1 || j <= version2.size() - 1;){
            if(i <= version1.size() - 1){
                if(version1[i] != '.')
                    s1 += version1[i];
                else{
                    if(s1 != "")
                        num1 = stoi(s1);
                    cflag1 = 1;
                    s1.clear();
                }
            }
            else{
                cflag1 = 1;
                if(s1 != "")
                    num1 = stoi(s1);
                s1.clear();
            }
            if(j <= version2.size() - 1){
                if(version2[j] != '.')
                    s2 += version2[j];
                else{
                    if(s2 != "")
                        num2 = stoi(s2);
                    cflag2 = 1;
                    s2.clear();
                }
            }
            else{
                cflag2 = 1;
                if(s2 != "")
                    num2 = stoi(s2);
                s2.clear();
            }
            if(cflag1 == 0)
                i++;
            if(cflag2 == 0)
                j++;
            if(cflag1 && cflag2 == 1){
                if(num1 > num2)
                    return 1;
                if(num1 < num2)
                    return -1;
                if(i >= version1.size() && j < version2.size())
                    num1 = 0;
                if(j >= version2.size() && i < version1.size())
                    num2 = 0;
                cflag1 = cflag2 = 0;
                i++; j++;
            }
        }
        if(s1 != "")
            num1 = stoi(s1);
        if(s2 != "")
            num2 = stoi(s2);
        if(num1 > num2)
            return 1;
        else if(num1 < num2)
            return -1;
        else
            return 0;
    }
};

int main()
{
    string s1 = "1.0", s2 = "1";
    Solution S;
    S.compareVersion(s1, s2);
    cout << "Hello world!" << endl;
    return 0;
}
