#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
      std::set<int> s;
      for (int i = 0; i < nums.size(); i++) {
        if (!s.count(nums[i])) {
          std::cout << nums[i] << std::endl;
          s.insert(nums[i]);
        }
        else {
          return true;
        }
      }
      return false;
    }
};
