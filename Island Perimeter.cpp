class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int islands = 0, neighbours = 0;

        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    islands++; 
                    if (i < n - 1 && grid[i + 1][j] == 1) neighbours++; 
                    if (j < m - 1 && grid[i][j + 1] == 1) neighbours++; 
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
};
