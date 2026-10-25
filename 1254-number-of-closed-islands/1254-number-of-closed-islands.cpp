class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 1)
                return;

            grid[r][c] = 1;

            dfs(r - 1, c);
            dfs(r + 1, c);
            dfs(r, c - 1);
            dfs(r, c + 1);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    bool closed = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 1;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        if (r == 0 || c == 0 || r == m - 1 || c == n - 1)
                            closed = false;

                        int dr[] = {-1, 1, 0, 0};
                        int dc[] = {0, 0, -1, 1};

                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 0) {
                                grid[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (closed)
                        count++;
                }
            }
        }

        return count;
    }
};