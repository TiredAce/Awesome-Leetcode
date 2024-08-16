/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (52.33%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    112.1K
 * Total Submissions: 214.2K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dist;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int x, int y, vector<vector<int>> &g)
    {
        if (dist[x][y]) return dist[x][y];

        int maxv = 0;
        for (int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= dist.size() || ny >= dist[0].size()) continue;
            if (g[nx][ny] <= g[x][y]) continue;
            maxv = max(maxv, dfs(nx, ny, g));
        }
        dist[x][y] = maxv + 1;
        return maxv + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dist = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < dist.size(); i ++)
        {
            for (int j = 0; j < dist[0].size(); j ++)
            {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};
// @lc code=end

