#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
      if (nums.size() == 0)
        return 0;
      std::set<int> s = {nums.begin(), nums.end()};

      auto it = s.begin();
      int count = 1;
      int prev = 0;
      int num = *it;
      while (it != s.end()) {
        if (s.find(num + 1) != s.end()) {
          count++;
          if (prev <= count)
            prev = count;
          num += 1;
        }
        else {
          if (prev <= count)
            prev = count;
          count = 1;
          num = *it;
        }
        it++;
      }
      std::cout << prev << std::endl;
      return prev;
    }
};
