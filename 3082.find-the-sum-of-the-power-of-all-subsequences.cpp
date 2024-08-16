/*
 * @lc app=leetcode.cn id=3082 lang=cpp
 *
 * [3082] Find the Sum of the Power of All Subsequences
 *
 * https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences/description/
 *
 * algorithms
 * Hard (48.66%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 5.9K
 * Testcase Example:  '[1,2,3]\n3'
 *
 * You are given an integer array nums of length n and a positive integer k.
 * 
 * The power of an array of integers is defined as the number of subsequences
 * with their sum equal to k.
 * 
 * Return the sum of power of all subsequences of nums.
 * 
 * Since the answer may be very large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:   nums = [1,2,3], k = 3 
 * 
 * Output:   6 
 * 
 * Explanation:
 * 
 * There are 5 subsequences of nums with non-zero power:
 * 
 * 
 * The subsequence [1,2,3] has 2 subsequences with sum == 3: [1,2,3] and
 * [1,2,3].
 * The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 * The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 * The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 * The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 * 
 * 
 * Hence the answer is 2 + 1 + 1 + 1 + 1 = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:   nums = [2,3,3], k = 5 
 * 
 * Output:   4 
 * 
 * Explanation:
 * 
 * There are 3 subsequences of nums with non-zero power:
 * 
 * 
 * The subsequence [2,3,3] has 2 subsequences with sum == 5: [2,3,3] and
 * [2,3,3].
 * The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
 * The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
 * 
 * 
 * Hence the answer is 2 + 1 + 1 = 4.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:   nums = [1,2,3], k = 7 
 * 
 * Output:   0 
 * 
 * Explanation: There exists no subsequence with sum 7. Hence all subsequences
 * of nums have power = 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * 1 <= nums[i] <= 10^4
 * 1 <= k <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (auto num: nums)
        {
            for (int i = nums.size(); i >= 1; i --)
            {
                for (int j = k; j >= num; j --)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - num]) % mod; 
                }
            }
        }
        int ans = 0, pow = 1;
        for (int i = nums.size(); i >= 1; i --)
        {
            ans = (ans + (long long)pow * dp[i][k]) % mod;
            pow = pow * 2 % mod;
        }
        return ans;
    }
};
// @lc code=end

