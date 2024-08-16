/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 *
 * [2328] 网格图中递增路径的数目
 *
 * https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/description/
 *
 * algorithms
 * Hard (52.15%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 16K
 * Testcase Example:  '[[1,1],[3,4]]'
 *
 * 给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4 个方向相邻的任意一个格子。
 * 
 * 请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是 严格递增 的路径数目。由于答案可能会很大，请将结果对 10^9 + 7 取余
 * 后返回。
 * 
 * 如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[1,1],[3,4]]
 * 输出：8
 * 解释：严格递增路径包括：
 * - 长度为 1 的路径：[1]，[1]，[3]，[4] 。
 * - 长度为 2 的路径：[1 -> 3]，[1 -> 4]，[3 -> 4] 。
 * - 长度为 3 的路径：[1 -> 3 -> 4] 。
 * 路径数目为 4 + 3 + 1 = 8 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[1],[2]]
 * 输出：3
 * 解释：严格递增路径包括：
 * - 长度为 1 的路径：[1]，[2] 。
 * - 长度为 2 的路径：[1 -> 2] 。
 * 路径数目为 2 + 1 = 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> vis;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int mod = 1e9 + 7;
    int dfs(int x, int y, vector<vector<int>>& g)
    {
        if (vis[x][y] == 0) return dp[x][y];
        int sums = 0;
        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size()) continue;
            if (g[x][y] >= g[nx][ny]) continue;
            sums = (sums + dfs(nx, ny, g)) % mod;
        }
        vis[x][y] = 0;
        dp[x][y] = (dp[x][y] + sums) % mod;
        return dp[x][y];
    }

    int countPaths(vector<vector<int>>& grid) {
        
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 1));
        vis = vector<vector<int>>(dp.begin(), dp.end());
        int ans = 0;
        for (int i = 0; i < grid.size(); i ++)
        {
            for (int j = 0; j < grid[0].size(); j ++)
            {
                if (vis[i][j] == 1) dfs(i, j, grid);
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;
    }
};
// @lc code=end

