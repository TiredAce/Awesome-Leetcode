/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] 最大得分的路径数目
 *
 * https://leetcode.cn/problems/number-of-paths-with-max-score/description/
 *
 * algorithms
 * Hard (38.98%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    9.7K
 * Total Submissions: 24.9K
 * Testcase Example:  '["E23","2X2","12S"]\r'
 *
 * 给你一个正方形字符数组 board ，你从数组最右下方的字符 'S' 出发。
 * 
 * 你的目标是到达数组最左上角的字符 'E' ，数组剩余的部分为数字字符 1, 2, ..., 9 或者障碍
 * 'X'。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。
 * 
 * 一条路径的 「得分」 定义为：路径上所有数字的和。
 * 
 * 请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对 10^9 + 7 取余。
 * 
 * 如果没有任何路径可以到达终点，请返回 [0, 0] 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = ["E23","2X2","12S"]
 * 输出：[7,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = ["E12","1X1","21S"]
 * 输出：[4,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = ["E11","XXX","11S"]
 * 输出：[0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= board.length == board[i].length <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), 0));
        vector<vector<int>> cnt(dp.begin(), dp.end());
        int n = board.size() - 1, m = board[0].size() - 1;
        cnt[n][m] = 1;
        int mod = 1e9 + 7;
        board[0][0] = '0';
        for (int i = n; i >= 0; i --)
        {
            for (int j = m; j >= 0; j --)
            {
                if (i == n && j == m) continue;
                if (board[i][j] == 'X') 
                {
                    dp[i][j] = -0x3f3f3f3f;
                    continue;
                }
                if (i == n)
                {
                    dp[i][j] = (dp[i][j + 1] + board[i][j] - '0') % mod;
                    cnt[i][j] = cnt[i][j + 1];
                }
                else if (j == m)
                {
                    dp[i][j] = (dp[i + 1][j] + board[i][j]- '0') % mod;
                    cnt[i][j] = cnt[i + 1][j];
                }
                else
                {
                    int dx[3] = {1, 1, 0};
                    int dy[3] = {0, 1, 1};

                    int maxv = 0;
                    for (int d = 0; d < 3; d ++)
                    {
                        int nx = i + dx[d], ny = j + dy[d];
                        maxv = max(maxv, dp[nx][ny]); 
                    }
                    for (int d = 0; d < 3; d ++)
                    {
                        int nx = i + dx[d], ny = j + dy[d];
                        if (maxv == dp[nx][ny])
                        {
                            cnt[i][j] = (cnt[i][j] + cnt[nx][ny]) % mod;
                        }
                    }
                    dp[i][j] = (maxv + board[i][j] - '0') % mod;
                }
            }
        }
        if (cnt[0][0] == 0) return {0, 0};
        else return {dp[0][0], cnt[0][0]};
    }
};
// @lc code=end

