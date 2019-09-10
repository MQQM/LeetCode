/*
  题目：
  给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

  示例 1:
  输入: "aba"
  输出: True

  示例 2:
  输入: "abca"
  输出: True
  解释: 你可以删除c字符。

  注意:
  字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

  参考：
  https://leetcode-cn.com/problems/valid-palindrome-ii/solution/cyu-yan-jian-jian-dan-dan-de-ji-xing-dai-ma-jie-17/
*/
class Solution
{
public:
    bool valid(string s)
    {
        int len = s.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return valid(s.substr(left + 1, right - (left + 1) + 1)) || valid(s.substr(left, right - 1 - left + 1));
            }
            left++;
            right--;
        }
        return true;
    }
};
