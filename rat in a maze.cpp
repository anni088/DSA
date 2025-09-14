class Solution {
    bool isSafe(vector<vector<int>> m, int n, vector<vector<int>> visited, int x, int y)
{
    if((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0)
    return 1;
    else
    return 0;
}


void solve(vector<vector<int>> maze, int n, vector<vector<int>>& visited,string path, vector<string>& ans, int x, int y)
{
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    //Right
    int newx = x;
    int newy = y+1;
    if(isSafe(maze, n, visited, newx, newy))
    {
        path += 'R';
        // visited[newx][newy] = 1;
        solve(maze, n, visited, path, ans, newx, newy);
        path.pop_back();
    }

    //Down
    newx = x+1;
    newy = y;
    if(isSafe(maze, n, visited, newx, newy))
    {
        path += 'D';
        solve(maze, n, visited, path, ans, newx, newy);
        path.pop_back();
    }

    //Left
    newx = x;
    newy = y-1;
    if(isSafe(maze, n, visited, newx, newy))
    {
        path += 'L';
        // visited[newx][newy] = 1;
        solve(maze, n, visited, path, ans, newx, newy);
        path.pop_back();
    }

    //Up
    newx = x-1;
    newy = y;
    if(isSafe(maze, n, visited, newx, newy))
    {
        path += 'U';
        // visited[newx][newy] = 1;
        solve(maze, n, visited, path, ans, newx, newy);
        path.pop_back();
    }

    visited[x][y] = 0;

}
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
    vector<string> ans;
        if(maze[0][0] == 0)
        return ans;
        int n = maze.size();
        vector<vector<int>> visited = maze;
        
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

    string path = "";

    solve(maze, n, visited, path, ans, 0, 0);
    
    sort(ans.begin(), ans.end());
    
    return ans;
    }
};
