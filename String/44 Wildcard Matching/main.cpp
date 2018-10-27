#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    if (m == 0)
      return n == 0;
    //回溯 st ,prev 记录 i 的值
    int st = -1,prev;
    int i = 0 , j = 0 ;
    while(i < n){
      if( j < m && (s[i] == p[j] || p[j] == '?')){
        i++;
        j++;
      }else if (p[j] == '*'){ //匹配1个
        prev = i;
        st = j;
        j++;
      }else if(st!=-1) {//有回溯状态，回溯匹配0个的时候prev++;
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
    //回溯 st ,prev 记录 i 的值
    int st = -1,prev;
    int i = 0 , j = 0 ;
    while(i < n){
      if( j < m && (s[i] == p[j] || p[j] == '?')){
        i++;
        j++;
      }else if (p[j] == '*'){ //匹配1个
        prev = i;
        st = j;
        j++;
      }else if(st!=-1) {//有回溯状态，回溯匹配0个的时候prev++;
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
