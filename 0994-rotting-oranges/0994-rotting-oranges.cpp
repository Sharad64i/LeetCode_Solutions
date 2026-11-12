class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /* there can be multiple rotten oranges so maintain a queue put all the
         rotten oranges in a queue and maintain a count of fresh oranges
        now all the elements stored in the queue are rotten for
        round one make all there nerightours rotten and put them in the queue do
        this till no more oranges could be rotten or no are remaining in the
        queue maintain a */
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                makeallnearrotten(grid, q, x, y,fresh);
            }
            minutes++;
        }
        if(fresh > 0){
            return -1;
        }
        return minutes;
    }
    void makeallnearrotten(vector<vector<int>>& grid, queue<pair<int, int>>& q,
                           int x, int y,int &fresh) {
        vector<int> dirx = {0, 0, -1, 1};
        vector<int> diry = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                if (grid[nx][ny] == 1) {
                    fresh--;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
};