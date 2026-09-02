#include <iostream>
#include <vector>
#include <algorithm> 


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int area = 0;
        int res = 0;
        int r = heights.size() - 1;
        while (l < r) {
            area = (r - l) * std::min(heights[l], heights[r]);
            res = std::max(res, area);
            if (heights[r] < heights[l]) {
                r -= 1;
            }
            else {
                l += 1;
            }
        }
        return res;
    }
};
