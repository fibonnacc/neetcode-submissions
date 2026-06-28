
class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::map<int, int> increment;
    for (int i = 0; i < nums.size(); i++) {
      increment[nums[i]] += 1;
    }
    std::vector<std::pair<int, int> > vec(increment.begin(), increment.end());
    
    std::sort(vec.rbegin(), vec.rend(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    std::vector<int> push;
    for (size_t i = 0; i < k; i++) {
      push.push_back(vec[i].first);
    }
    return push;
  }
};
