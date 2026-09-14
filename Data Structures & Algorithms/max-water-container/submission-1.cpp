class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left_max = 0;
        int right_max = heights.size() - 1;
        int area = 0;
        int new_area = 0;
        while (left_max < right_max) {

            int width = right_max - left_max;
            int height = std::min(heights[left_max], heights[right_max]);
            new_area = width * height;

            if (area < new_area) {
                area = new_area;
            }
            if (heights[left_max] < heights[right_max]) {
                left_max++;
            }
            else if (heights[left_max] > heights[right_max]) {
                right_max--;
            }
            else {
                right_max--;
                left_max++;
            }
        }
        std::cout << "Area : " << area << std::endl;
        return area;
    }
};
