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
        int count;
        for(int travel_num = 0; travel_num < word_len; travel_num++){
            int i = travel_num;
            while(i < s.size()){ //一次遍历把除3余0序列搞定，重复三趟
                N = M;
                count = 0;
                int j = i;
                while(count < num){
                    string sub = s.substr(j, word_len);
                    if(!N.count(sub)){
                        j += word_len;
                        break;
                    }
                    if(--N[sub] >= 0){
                        count++;
                        j += word_len;
                    }
                    else{
                        j = i + word_len;;
                        break;
                    }
                }
                if(count == num){
                    V.push_back(i);
                    j = i + word_len;
                }
                i = j;
            }
        }
        return V;
    }
};

