class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || !words.size()) return result;

        hash<string> hash_fn;
        int word_len = words[0].length();
        int words_cnt = words.size();
        size_t hash_sum = 0;

        for (int k = 0; k < words_cnt; k++) {
            hash_sum += hash_fn(words[k]);
        }

        for(int offset = 0 ; offset < word_len; offset++) {
            int i = offset;
            size_t tmp_hash_sum = 0;

            for(; i <= offset + (words_cnt - 1) * word_len && i < s.length(); i += word_len) {
                tmp_hash_sum += hash_fn(s.substr(i, word_len));
            }

            if(tmp_hash_sum == hash_sum) result.push_back(i - words_cnt * word_len);

            for(; i < s.length(); i += word_len) {
                tmp_hash_sum -= hash_fn(s.substr(i - words_cnt * word_len, word_len));
                tmp_hash_sum += hash_fn(s.substr(i, word_len));
                if(tmp_hash_sum == hash_sum) result.push_back(i - (words_cnt - 1) * word_len);
            }
        }

        return result;
    }
};
