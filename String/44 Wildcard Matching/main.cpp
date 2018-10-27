#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    if (m == 0)
      return n == 0;
    //���� st ,prev ��¼ i ��ֵ
    int st = -1,prev;
    int i = 0 , j = 0 ;
    while(i < n){
      if( j < m && (s[i] == p[j] || p[j] == '?')){
        i++;
        j++;
      }else if (p[j] == '*'){ //ƥ��1��
        prev = i;
        st = j;
        j++;
      }else if(st!=-1) {//�л���״̬������ƥ��0����ʱ��prev++;
        prev++;
        i = prev;
        j = st + 1;
      }
      else return false;
    }
    while(j < m && p[j]=='*') j++;
    return j == m;
  }
};

int main()
{
    string s = "aa", p = "a";
    Solution S;
    S.isMatch(s, p);
    return 0;
}
/*
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    if (m == 0)
      return n == 0;
    //���� st ,prev ��¼ i ��ֵ
    int st = -1,prev;
    int i = 0 , j = 0 ;
    while(i < n){
      if( j < m && (s[i] == p[j] || p[j] == '?')){
        i++;
        j++;
      }else if (p[j] == '*'){ //ƥ��1��
        prev = i;
        st = j;
        j++;
      }else if(st!=-1) {//�л���״̬������ƥ��0����ʱ��prev++;
        prev++;
        i = prev;
        j = st;
      }
      else return false;
    }
    while(j < m && p[j]=='*') j++;
    return j == m;
  }
};
*/
