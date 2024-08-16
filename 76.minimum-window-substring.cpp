/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (46.09%)
 * Likes:    2963
 * Dislikes: 0
 * Total Accepted:    615.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int minl = 0x3f3f3f3f, lf;
        int l = 0;
        int cnt[200] = {0};
        int vis[200] = {0};
        int flag = 0;
        for (char c: t)
        {
            vis[c] = 1;
            cnt[c] ++;
            if (cnt[c] == 1) flag ++;
        }
        for (int i = 0; i < s.size(); i ++)
        {
            if (vis[s[i]]){
                cnt[s[i]] --;
                if (cnt[s[i]] == 0) flag --;
            }
            while (flag <= 0)
            {
                if (i - l + 1 < minl) minl = i - l + 1, lf = l;
                if (vis[s[l]])
                {
                    cnt[s[l]] ++;
                    if (cnt[s[l]] == 1) flag ++;
                }
                l ++;
            }
        }
        if (minl > s.size()) return "";
        return s.substr(lf, minl);
    }
};
// @lc code=end

