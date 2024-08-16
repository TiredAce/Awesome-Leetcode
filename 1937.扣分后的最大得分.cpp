/*
 * @lc app=leetcode.cn id=1937 lang=cpp
 *
 * [1937] 扣分后的最大得分
 *
 * https://leetcode.cn/problems/maximum-number-of-points-with-cost/description/
 *
 * algorithms
 * Medium (30.93%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 21K
 * Testcase Example:  '[[1,2,3],[1,5,1],[3,1,1]]'
 *
 * 给你一个 m x n 的整数矩阵 points （下标从 0 开始）。一开始你的得分为 0 ，你想最大化从矩阵中得到的分数。
 * 
 * 你的得分方式为：每一行 中选取一个格子，选中坐标为 (r, c) 的格子会给你的总得分 增加 points[r][c] 。
 * 
 * 然而，相邻行之间被选中的格子如果隔得太远，你会失去一些得分。对于相邻行 r 和 r + 1 （其中 0 ），选中坐标为 (r, c1) 和 (r +
 * 1, c2) 的格子，你的总得分 减少 abs(c1 - c2) 。
 * 
 * 请你返回你能得到的 最大 得分。
 * 
 * abs(x) 定义为：
 * 
 * 
 * 如果 x >= 0 ，那么值为 x 。
 * 如果 x  ，那么值为 -x 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：points = [[1,2,3],[1,5,1],[3,1,1]]
 * 输出：9
 * 解释：
 * 蓝色格子是最优方案选中的格子，坐标分别为 (0, 2)，(1, 1) 和 (2, 0) 。
 * 你的总得分增加 3 + 5 + 3 = 11 。
 * 但是你的总得分需要扣除 abs(2 - 1) + abs(1 - 0) = 2 。
 * 你的最终得分为 11 - 2 = 9 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[1,5],[2,3],[4,2]]
 * 输出：11
 * 解释：
 * 蓝色格子是最优方案选中的格子，坐标分别为 (0, 1)，(1, 1) 和 (2, 0) 。
 * 你的总得分增加 5 + 3 + 4 = 12 。
 * 但是你的总得分需要扣除 abs(1 - 1) + abs(1 - 0) = 1 。
 * 你的最终得分为 12 - 1 = 11 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == points.length
 * n == points[r].length
 * 1 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(), 0));
        for (int i = 0; i < dp[0].size(); i ++) dp[0][i] = points[0][i];

        for (int i = 0; i < dp.size() - 1; i ++)
        {
            long long maxv = 0;
            for (int j = 0; j < dp[0].size(); j ++)
            {
                maxv = max(maxv, dp[i][j] + j);
                dp[i + 1][j] = maxv + points[i + 1][j] - j;
            }
            maxv = -0x3f3f3f3f;
            for (int j = dp[0].size() - 1; j >= 0; j --)
            {
                maxv = max(maxv, dp[i][j] - j);
                dp[i + 1][j] = max(dp[i + 1][j], maxv + points[i + 1][j] + j);
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < dp[0].size(); i ++)
            ans = max(ans, dp[dp.size() - 1][i]);
        return ans;
    }
};
// @lc code=end

