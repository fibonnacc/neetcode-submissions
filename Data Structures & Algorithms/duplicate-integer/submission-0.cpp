#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
      std::unordered_set<int> seen;
      for (int x : nums) {
        if (seen.count(x))
          return true;
        seen.insert(x);
      }
      return false;
    }
};
