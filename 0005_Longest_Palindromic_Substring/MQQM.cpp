/*
  题目：
  给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

  示例 1：
  输入: "babad"
  输出: "bab"
  注意: "aba" 也是一个有效答案。

  示例 2：
  输入: "cbbd"  
  输出: "bb"

  做法：动态规划，二位dp数组
  https://blog.csdn.net/shineboyxxb/article/details/52079360
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len <= 1)
        { // 空串 或 字符串长度为1
            return s;
        }
        bool dp[len][len] = {false};

        int max_len = 1;
        int start = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == i)
                {
                    dp[j][i] = true;
                }
                else if (i - j == 1)
                {
                    dp[j][i] = (s[j] == s[i]);
                }
                else
                {
                    dp[j][i] = (s[j] == s[i]) && dp[j + 1][i - 1];
                }
                if (dp[j][i] && max_len < (i - j + 1))
                {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};
