class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //�����ڽӱ�
        vector<int>  adj[numCourses];
        for(auto p : prerequisites)
            adj[p.second].push_back(p.first);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for(int i = 0; i < numCourses; i++)
            if(!visited[i] && cycle(adj, visited, onpath, i))
                return false;
        return true;
    }
    bool cycle(vector<int> adj[], vector<bool> &visited, vector<bool> &onpath, int i){
        visited[i] = onpath[i] = true;
        for(int j = 0; j < adj[i].size(); j++){
            if(!visited[adj[i][j]] && cycle(adj, visited, onpath, adj[i][j]))
                return true;
            if(onpath[adj[i][j]])  //?���ڵݹ�·���ϵ�ΪTrue
                return true;
        }
        onpath[i] = false;
        return false;
    }
};
