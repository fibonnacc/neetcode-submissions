#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int> mp;
      for (int i = 0; i < nums.size(); i++) {
        int value = target - nums[i];
        if (mp.count(value) > 0) {
          return {mp[value], i};
        }
        mp[nums[i]] = i;
      }
      return std::vector<int>();
    }
};
