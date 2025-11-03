class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        for (auto& w : walls) grid[w[0]][w[1]] = 2;

        auto mark_guarded = [&](int r, int c) {
            for (int row = r + 1; row < m; ++row) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            for (int row = r - 1; row >= 0; --row) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            for (int col = c + 1; col < n; ++col) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
            for (int col = c - 1; col >= 0; --col) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
        };

        for (auto& g : guards) {
            mark_guarded(g[0], g[1]);
        }

        int res = 0;
        for (auto& row : grid)
            for (auto cell : row)
                if (cell == 0)
                    res++;

        return res; 
    }
};