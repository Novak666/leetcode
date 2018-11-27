#include <iostream>

using namespace std;

class Solution {
public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        //very interesting problem
        //It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
        //Then the queue becomes a queue of paths.
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if (wordset.find(endWord) == wordset.end())
            return {};
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        paths.push({beginWord});
        int level = 1;
        int flag = 0;
        //"visited" records all the visited nodes on this level
        //these words will never be visited again after this level
        //and should be removed from wordset. This is guaranteed
        // by the shortest path.
        unordered_set<string> visited;

        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                //reach a new level
                for (string w : visited) wordset.erase(w);
                visited.clear();
                if(flag == 1) break;
                level = path.size();
            }
            string last = path.back();
            //find next words in wordset by changing
            //each element from 'a' to 'z'
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (wordset.find(news) != wordset.end()) {
                    //next word is in wordset
                    //append this word to path
                    //path will be reused in the loop
                    //so copy a new path
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            flag = 1;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
