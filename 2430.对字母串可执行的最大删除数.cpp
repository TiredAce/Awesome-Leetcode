/*
 * @lc app=leetcode.cn id=2430 lang=cpp
 *
 * [2430] 对字母串可执行的最大删除数
 *
 * https://leetcode.cn/problems/maximum-deletions-on-a-string/description/
 *
 * algorithms
 * Hard (48.98%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 16.2K
 * Testcase Example:  '"abcabcdabc"'
 *
 * 给你一个仅由小写英文字母组成的字符串 s 。在一步操作中，你可以：
 * 
 * 
 * 删除 整个字符串 s ，或者
 * 对于满足 1 <= i <= s.length / 2 的任意 i ，如果 s 中的 前 i 个字母和接下来的 i 个字母 相等 ，删除 前 i
 * 个字母。
 * 
 * 
 * 例如，如果 s = "ababc" ，那么在一步操作中，你可以删除 s 的前两个字母得到 "abc" ，因为 s 的前两个字母和接下来的两个字母都等于
 * "ab" 。
 * 
 * 返回删除 s 所需的最大操作数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcabcdabc"
 * 输出：2
 * 解释：
 * - 删除前 3 个字母（"abc"），因为它们和接下来 3 个字母相等。现在，s = "abcdabc"。
 * - 删除全部字母。
 * 一共用了 2 步操作，所以返回 2 。可以证明 2 是所需的最大操作数。
 * 注意，在第二步操作中无法再次删除 "abc" ，因为 "abc" 的下一次出现并不是位于接下来的 3 个字母。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaabaab"
 * 输出：4
 * 解释：
 * - 删除第一个字母（"a"），因为它和接下来的字母相等。现在，s = "aabaab"。
 * - 删除前 3 个字母（"aab"），因为它们和接下来 3 个字母相等。现在，s = "aab"。 
 * - 删除第一个字母（"a"），因为它和接下来的字母相等。现在，s = "ab"。
 * - 删除全部字母。
 * 一共用了 4 步操作，所以返回 4 。可以证明 4 是所需的最大操作数。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "aaaaa"
 * 输出：5
 * 解释：在每一步操作中，都可以仅删除 s 的第一个字母。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 4000
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();

        vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i --)
        {
            for (int j = i + 1; j < n; j ++)
            {
                if (s[i] == s[j])
                {
                    lcs[i][j] = lcs[i + 1][j + 1] + 1;
                }
            }
        }

        vector<int> dp2(n + 1, 1);
        for (int i = n - 1; i >= 0; i --)
        {
            int len = n - i;
            for (int l = 1; l <= len / 2; l ++)
            {
                if (lcs[i][i + l] >= l) dp2[i] = max(dp2[i], dp2[i+l] + 1);
            }
        }
        return dp2[0];
    }
};
// @lc code=end

