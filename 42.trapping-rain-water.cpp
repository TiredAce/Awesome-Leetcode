/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (63.98%)
 * Likes:    5255
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st; // big -> small top
        for (int i = 0; i < height.size(); i ++)
        {
            int maxh = 0;
            while (st.size() && height[i] >= height[st.top()])
            {
                ans += (i - st.top() - 1) * (height[st.top()] - maxh);
                maxh = height[st.top()];
                st.pop();
            }
            if (st.size()) 
                ans += (i - st.top() - 1) * (height[i] - maxh);
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

