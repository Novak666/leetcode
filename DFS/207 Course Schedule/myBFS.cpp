#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto p : prerequisites)
            adj[p.second].push_back(p.first);
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++)
            indegree[prerequisites[i].first]++;
        queue<int> Q;
        for(int i = 0; i < numCourses; i++)
            if(!indegree[i])
                Q.push(i);
        int count = 0;
        while(!Q.empty()){
            int p = Q.front();
            Q.pop();
            count++;
            for(int i = 0; i < adj[p].size(); i++)
                    if(!(--indegree[adj[p][i]]))  //Ð¡ÐÄbug
                        Q.push(adj[p][i]);
        }
        return count == numCourses;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
