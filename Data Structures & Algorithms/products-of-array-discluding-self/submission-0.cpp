#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
      int i = 1;
      int j = nums.size() - 1;
      std::vector<int> pref(nums.size(),1);
      std::vector<int> suff(nums.size(),1);
      pref[0] = nums[0];
      suff[j] = nums[j];
      while(i < nums.size() ){
        pref[i] = pref[i - 1] * nums[i];
        suff[j - 1] = suff[j] * nums[j - 1];
        i++;
        j--;
      }


      std::vector<int> res;
      i = 0;
      res.push_back(suff[1]);
      i++;
      while (i < nums.size() - 1) {

        int num = pref[i - 1] * suff[i + 1];
        res.push_back(num);
        i++;
      }
      res.push_back(pref[nums.size() - 2]);
      return res;
    }
};

