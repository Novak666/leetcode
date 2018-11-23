class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //构建邻接表
        vector<int>  adj[numCourses];
        for(auto p : prerequisites)
            adj[p.second].push_back(p.first);
        vector<int> order;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for(int i = 0; i < numCourses; i++)
            if(!visited[i] && cycle(adj, visited, onpath, i, order))
                return {};
        reverse(order.begin(), order.end());
        return order;
    }
    bool cycle(vector<int> adj[], vector<bool> &visited, vector<bool> &onpath, int i, vector<int> &order){
        visited[i] = onpath[i] = true;
        for(int j = 0; j < adj[i].size(); j++){
            if(!visited[adj[i][j]] && cycle(adj, visited, onpath, adj[i][j], order))
                return true;
            if(onpath[adj[i][j]])  //?正在递归路径上的为True
                return true;
        }
        order.push_back(i);
        onpath[i] = false;
        return false;
    }
};
/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};
*/
