/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 *
 * [2787] 将一个数字表示成幂的和的方案数
 *
 * https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/description/
 *
 * algorithms
 * Medium (48.40%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 13.6K
 * Testcase Example:  '10\n2'
 *
 * 给你两个 正 整数 n 和 x 。
 * 
 * 请你返回将 n 表示成一些 互不相同 正整数的 x 次幂之和的方案数。换句话说，你需要返回互不相同整数 [n1, n2, ..., nk]
 * 的集合数目，满足 n = n1^x + n2^x + ... + nk^x 。
 * 
 * 由于答案可能非常大，请你将它对 10^9 + 7 取余后返回。
 * 
 * 比方说，n = 160 且 x = 3 ，一个表示 n 的方法是 n = 2^3 + 3^3 + 5^3^ 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 10, x = 2
 * 输出：1
 * 解释：我们可以将 n 表示为：n = 3^2 + 1^2 = 10 。
 * 这是唯一将 10 表达成不同整数 2 次方之和的方案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 4, x = 1
 * 输出：2
 * 解释：我们可以将 n 按以下方案表示：
 * - n = 4^1 = 4 。
 * - n = 3^1 + 1^1 = 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 300
 * 1 <= x <= 5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 1; pow(i, x) <= n; i ++)
        {
            for (int j = n; j >= pow(i, x); j --)
            {
                dp[j] = (dp[j] + dp[j - pow(i, x)]) % mod;
            }
        }
        return dp[n];
    }
};
// @lc code=end

