class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int value = numbers[right] + numbers[left];
            if (value == target) {
                return {left+1, right+1};
            }
            else if (value > target) {
                right--;
            }
            else if (value < target) {
                left++;
            }
        }
        return {};
    }
};
