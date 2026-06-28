#include <cctype>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
      int size_s = s.length() - 1;
      int i = 0;
      int j = s.length() / 2;
      while (j > 0 && i < s.length() && size_s > 0) {
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
        j--;
      }
      return true;
    }
};
