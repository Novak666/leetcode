class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == '1'){
                    numIslands++;
                    bfs(grid, i, j);
                }
        return numIslands;
    }
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<vector<int>> Q;
        Q.push({i, j});
        grid[i][j] = 0;
        while(!Q.empty()){
            i = Q.front()[0];
            j = Q.front()[1];
            Q.pop();
            if(i > 0 && grid[i - 1][j] == '1'){
                grid[i - 1][j] = 0;
                Q.push({i - 1, j});
            }
            if(i + 1 < grid.size() && grid[i + 1][j] == '1'){
                grid[i + 1][j] = 0;
                Q.push({i + 1, j});
            }
            if(j > 0 && grid[i][j - 1] == '1'){
                grid[i][j - 1] = 0;
                Q.push({i, j - 1});
            }
            if(j + 1 < grid[i].size() && grid[i][j + 1] == '1'){
                grid[i][j + 1] = 0;
                Q.push({i, j + 1});
            }
        }
    }
};
