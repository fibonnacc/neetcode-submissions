#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {   
      std::unordered_map<int, int> ma; 
      int i = 0;
      while (i < nums.size()) {
        int val = target - nums[i];
        if (ma.find(val) != ma.end()) {
        //   std::cout << "[ " << ma[val] << ", " << i << " ]" << std::endl;
          return {ma[val] + 1, i + 1};
        }
        ma[nums[i]] = i;
        i++;
      }
      return {};
    }
};


