#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s == "" || !words.size())
            return {};
        vector<int> V;
        int word_len = words[0].size();
        int num = words.size();
        unordered_map <string, int> M, N;
        for(auto temp : words)
            if(!M.count(temp))
                M[temp]++;
            else
                M[temp]++;
        int count;
        for(int i = 0; i < s.size(); i++){
            N = M;
            count = 0;
            int j = i;
            while(count < num){
                string sub = s.substr(j, word_len);
                if(!N.count(sub))
                    break;
                if(--N[sub] >= 0){
                    count++;
                    j = j + word_len;
                }
                else
                    break;
            }
            if(count < num)
                continue;
            V.push_back(i);
        }
        return V;
    }
};

int main()
{
    Solution S;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    S.findSubstring(s, words);
    cout << "Hello world!" << endl;
    return 0;
}
