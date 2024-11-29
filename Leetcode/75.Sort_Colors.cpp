class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int current = 0;

        while (current <= right) {
            if (nums[current] == 0) {
                // 把 0 移動到左邊
                swap(nums[current], nums[left]);
                left++;
                current++;
            } else if (nums[current] == 2) {
                // 把 2 移動到右邊
                swap(nums[current], nums[right]);
                right--;
            } else {
                // 如果是 1，不需要移動
                current++;
            }
        }
    }
};
