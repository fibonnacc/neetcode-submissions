class Solution {
  public:
    std::vector<std::vector<int>> TwoSum(std::vector<int> nums, int index, int target) {
      int left = 0;
      int right = nums.size() - 1;
      int sum = 0;
      std::vector<std::vector<int>> vec;
      while (left < right) {
        if (left == index) {
          left++;
          continue;
        }
        if (right == index) {
          right--;
          continue;
        }
        sum = nums[left] + nums[right] + target;
        if (sum == 0) {
          // std::cout << "{ " << target << " " << nums[left] << " " << nums[right] << " }" << std::endl;
          vec.push_back({target ,nums[left], nums[right]}) ;
          left++;
        }
        if (sum < 0) {
          left++;
        }
        else if (sum > 0) {
          right--;
        }
        else {
          right--;
          left++;
        }
      }
      return vec;
    }
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
      std::sort(nums.begin(), nums.end());
      std::vector<std::vector<int>> big_vec;
      std::set<std::vector<int>> se;
      for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])
        {
          continue;
        }
        std::vector<std::vector<int>> vec = TwoSum(nums, i, nums[i]);
        if (!vec.empty()) {
          for (int k = 0; k < vec.size(); k++) {
            std::sort(vec[k].begin(), vec[k].end());
            if (se.find(vec[k]) == se.end()) {
              se.insert(vec[k]);
              big_vec.push_back(vec[k]);
            }
          }
        }
      }
      // for (int i = 0; i < big_vec.size(); i++) {
      //   std::cout << " {";
      //   for (int j = 0; j < big_vec[i].size(); j++) {
      //     std::cout << big_vec[i][j] << " ";
      //   }
      //   std::cout << "}" << std::endl;
      // }
      return big_vec;
    }
};
