class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        //edge case
        if (wordset.find(endWord) == wordset.end())
            return 0;
        // two end bfs
        unordered_set<string> s1{beginWord};
        unordered_set<string> s2{endWord};
        while (!s1.empty()) {
            unordered_set<string> temp;
            for (auto word : s1)
                wordset.erase(word);
            for (auto word : s1) {
                for (int i = 0; i < word.size() ; i++) {
                    string next_word = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        next_word[i] = c;
                        if (wordset.find(next_word) == wordset.end())
                            continue;
                        if (next_word == endWord)
                            return ++ans;
                        temp.insert(next_word);
                    }
                }
            }
            ans++;
            s1 = temp;
        }

        return 0;
    }
};
