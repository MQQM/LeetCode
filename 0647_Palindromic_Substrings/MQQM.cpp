/*
  题目：
  给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
  具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

  示例 1:
  输入: "abc"
  输出: 3
  解释: 三个回文子串: "a", "b", "c".

  示例 2:
  输入: "aaa"
  输出: 6
  说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 
  注意:
  输入的字符串长度不会超过1000。

  做法：动态规划，二维dp数组。找所有子串
*/
class Solution
{
public:
    int countSubstrings(string s)
    {
        int len = s.size();
        int dp[len][len] = {false};

        int cnt = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
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
                if (dp[j][i])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
