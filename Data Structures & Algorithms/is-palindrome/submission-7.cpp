#include <cctype>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
      int size_s = s.length() - 1;
      int i = 0;
      int j = 0;
      if (s.length() == 2)
      {
        if (std::isalnum(s[0]) && std::isalnum(s[1])) {
          if (std::tolower(s[0]) != std::tolower(s[1])) {
            return false;
          }
        }

      }
      while (i <= s.length() / 2 && size_s >= s.length() / 2) {
        if (!std::isalnum(s[i])) {
          i++;
          continue;
        }
        if (!std::isalnum(s[size_s])) {
          size_s--;
          continue;
        }
        if (std::tolower(s[size_s]) != std::tolower(s[i]))
          return false;
        i++;
        size_s--;
      }
      return true;
    }
};
