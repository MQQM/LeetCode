/*
  题目：
  给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

  说明：本题中，我们将空字符串定义为有效的回文串。

  示例 1:
  输入: "A man, a plan, a canal: Panama"
  输出: true

  示例 2:
  输入: "race a car"
  输出: false  
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (!isalpha(s[left]) && !isdigit(s[left]))
            {
                left++;
            }
            else if (!isalpha(s[right]) && !isdigit(s[right]))
            {
                right--;
            }
            else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};
