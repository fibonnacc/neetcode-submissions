class Solution {
	public:
		int largestRectangleArea(std::vector<int>& heights) {
			int i = 0;
			int Area = 0;
      int start = 0;
			std::stack<std::vector<int>> st;
			while(i < heights.size()) {
        start = i;
        while (!st.empty() && st.top()[1] > heights[i]) {
          int height = st.top()[1];
          int index = st.top()[0];
          Area = std::max(Area, height * (i - index));
          st.pop();
          start = index;
        }
        st.push({start, heights[i]});
				i++;
			}
      i = 0;
      while (!st.empty()) {
        int height = st.top()[1];
        int index = st.top()[0];
        int width = heights.size() - index;
        Area = std::max(Area, height * width);
        st.pop();
      }
			return Area;
		}
};
