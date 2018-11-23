class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        //build graph
        vector<vector<int>> graph(numCourses, vector<int>(0, 0));
        for(auto p:prerequisites)
        {
            graph[p.first].push_back(p.second);
        }

        vector<int> order;
        vector<int> dependent(numCourses, false);
        vector<int> visited(numCourses, false);
        for(int i=0; i<numCourses; i++)
        {
            if(!dfs(i, graph, dependent, visited, order)) return vector<int>(0, 0);
        }

        return order;
    }


    bool dfs(int course, vector<vector<int>> &graph, vector<int> &dependent, vector<int> &visited, vector<int> &order)
    {
        if(dependent[course]) return false;
        if(visited[course]) return true;
        visited[course]=true;
        dependent[course]=true;
        for(auto g:graph[course])
        {
            if(!dfs(g, graph, dependent, visited, order)) return false;
        }
        dependent[course]=false;
        order.push_back(course);
        return true;

    }
};
