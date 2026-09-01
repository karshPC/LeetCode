class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> litterMask(m, vector<int>(n, 0));

        int sr = 0, sc = 0;
        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litterMask[i][j] = 1 << k++;
                }
            }
        }

        if (k == 0)
            return 0;

        int full = (1 << k) - 1;

        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        queue<array<int, 3>> q;

        best[sr][sc][0] = energy;
        q.push({sr * n + sc, 0, energy});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            moves++;

            while (sz--) {
                auto [pos, mask, e] = q.front();
                q.pop();

                int r = pos / n;
                int c = pos % n;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask | litterMask[nr][nc];

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    if (nmask == full)
                        return moves;

                    if (ne <= best[nr][nc][nmask])
                        continue;

                    best[nr][nc][nmask] = ne;
                    q.push({nr * n + nc, nmask, ne});
                }
            }
        }

        return -1;
    }
};