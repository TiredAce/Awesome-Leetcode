/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 *
 * https://leetcode.cn/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (54.52%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    32.6K
 * Total Submissions: 59.8K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * 给你一个 n x n 的网格 grid ，代表一块樱桃地，每个格子由以下三种数字的一种来表示：
 * 
 * 
 * 0 表示这个格子是空的，所以你可以穿过它。
 * 1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
 * -1 表示这个格子里有荆棘，挡着你的路。
 * 
 * 
 * 请你统计并返回：在遵守下列规则的情况下，能摘到的最多樱桃数：
 * 
 * 
 * 从位置 (0, 0) 出发，最后到达 (n - 1, n - 1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为 0 或者 1
 * 的格子）；
 * 当到达 (n - 1, n - 1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
 * 当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为 0 ）；
 * 如果在 (0, 0) 和 (n - 1, n - 1) 之间不存在一条可经过的路径，则无法摘到任何一个樱桃。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[0,1,-1],[1,0,-1],[1,1,1]]
 * 输出：5
 * 解释：玩家从 (0, 0) 出发：向下、向下、向右、向右移动至 (2, 2) 。
 * 在这一次行程中捡到 4 个樱桃，矩阵变成 [[0,1,-1],[0,0,-1],[0,0,0]] 。
 * 然后，玩家向左、向上、向上、向左返回起点，再捡到 1 个樱桃。
 * 总共捡到 5 个樱桃，这是最大可能值。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 50
 * grid[i][j] 为 -1、0 或 1
 * grid[0][0] != -1
 * grid[n - 1][n - 1] != -1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.size();
        vector<vector<int>> dp(n,  vector<int>(n, -0x3f3f3f3f));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n + m - 1; i ++)
        {
            for (int x1 = n - 1; x1 >= 0; x1 --)
            {
                int y1 = i - x1;
                for (int x2 = n - 1; x2 >= 0; x2 --)
                {
                    int y2 = i - x2;
                    if (y2 < 0 || y2 >= n || y1 < 0 || y1 >= n)
                    {
                        continue;
                    }
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
                    {
                        dp[x1][x2] = -0x3f3f3f3f;
                        continue;
                    }
                    int t = -0x3f3f3f3f;
                    if (x1) t = max(t, dp[x1 - 1][x2]);
                    if (x2) t = max(t, dp[x1][x2 - 1]);
                    if (x1 && x2) t = max(t, dp[x1 - 1][x2 - 1]);
                    t = max(t, dp[x1][x2]);
                    if (x1 != x2)
                        dp[x1][x2] = t + grid[x1][y1] + grid[x2][y2];
                    else
                        dp[x1][x2] = t + grid[x1][y1];
                }
            }
        }
        return max(0, dp[n - 1][n - 1]);
    }
};
// @lc code=end

