#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> M, N;
        pair<int, int> data = {INT_MAX, INT_MAX};
        for(char c : t)
            M[c];
        for(char c : t)
            N[c]++;
        int n = s.size();
        int len = INT_MAX;
        int left = 0;
        for(int i = 0; i < n; i++){
            if(!M.count(s[i])) continue;
            M[s[i]]++;
            while(contain(M, N)){
                if(len > i + 1 - left){
                    len = i + 1 - left;
                    data = {left, i};
                }
                left++;
                if(M.count(s[left - 1]))
                    M[s[left - 1]]--;
            }
        }
        int temp = (len != INT_MAX) ? len : 0;
        if(temp)
            return s.substr(data.first, temp);
        return "";
    }
    bool contain(unordered_map<char, int> M, unordered_map<char, int> N){
        for(auto item : M) //体会这段程度我和解答的差距，太低效了
            if(item.second < N[item.first])
                return false;
        return true;
    }
};

int main(){
    Solution S;
    //"ADOBECODEBANC", T = "ABC"
    string s = "ADOBECODEBANC", t = "ABC";
    S.minWindow(s,t);
}

