class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Traverse all collect all the starting index put them inside a queue
        // maintain a count of fresh oranges
        //  make a direction array
        //  start with the first level pop out front and check if there
        //  neighhours are fresh rotten them and add them in the queue keep
        //  doing it until no fresh oranges are left or no elements are left
        //  inside the queue
        queue<pair<int, int>> q;
        int fresh = 0;
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
                markallpush(grid, x, y, q, fresh);
            }
            minutes++;
        }
        if (fresh > 0) {
            return -1;
        }
        return minutes;
    }
    void markallpush(vector<vector<int>>& grid, int x, int y,
                     queue<pair<int, int>>& q, int& fresh) {
        vector<int> dirx = {0, 0, -1, 1};
        vector<int> diry = {1, -1, 0, 0};
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