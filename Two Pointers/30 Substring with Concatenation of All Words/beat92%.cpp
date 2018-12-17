//count难以维护，干脆去掉count，改区间长度
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
                M[temp]++;
        for(int k = 0; k < word_len; k++){
            int i = k;
            N.clear();
            int j = i;
            while(j < s.size()){
                string sub = s.substr(j, word_len);
                if(!M.count(sub)){
                    j += word_len;
                    i = j;
                    N.clear();
                    continue;
                }
                if(++N[sub] <= M[sub])
                    j += word_len;
                else{ //继续优化
                    while(N[sub] > M[sub]){
                        string str = s.substr(i, word_len);
                        i += word_len;
                        --N[str];
                    }
                    j += word_len;
                }
                if((j - i) == word_len * num)
                    V.push_back(i);
            }
        }
        return V;
    }
};

//参考
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        unordered_map<string, int> dict;
        for(string& word : words) ++dict[word];
        for(int k = 0, size = words[0].size(); k < size; k++) {
            unordered_map<string, int> m;
            int i = k, j = k;
            while(j < s.size()) {
                string word = s.substr(j, size);
                if (dict.find(word) == dict.end()) {
                    m.clear();
                    j += size, i = j;
                }
                else {
                    ++m[word];
                    while(m[word] > dict[word]) { //???
                        string str = s.substr(i, size);
                        i += size;
                        --m[str];
                    }
                    if (j-i+size == words.size()*size) res.push_back(i);
                    j += size;
                }
            }
        }
        return res;
    }
};

