#define pii pair<int, int>
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};
class Solution {
public:
    queue<pii> q;
    int n, m, vis[11][11];
    bool valid(int x, int y, vector<vector<int>>& grid) {
        if(x >= 0 and x < n and y >= 0 and y < m and !vis[x][y] and grid[x][y]) return true;
        else return false;
    }
    int bfs(vector<vector<int>>& grid) {
        int step = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                pii top = q.front();
                int x = top.first;
                int y = top.second;
                q.pop();
                for(int k=0; k<4; k++) {
                    int tx = x + fx[k];
                    int ty = y + fy[k];
                    if(valid(tx, ty, grid)) {
                        vis[tx][ty] = 1;
                        q.push({tx, ty});
                    }
                }
            }
            step++;
        }
        return step;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int ans = max(0, bfs(grid));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(vis[i][j] == 0 and grid[i][j] == 1) return -1;
        return ans;
    }
};