class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  // 避免溢位，計算中間索引
            
            // 如果找到目標值，直接返回索引
            if (nums[mid] == target) {
                return mid;
            }
            
            // 檢查左半部分是否有序
            // 若中間數大於最左邊數，則左半段是有序的
            // 4　　5　　6　　7　　0　　1　　2
            if (nums[left] <= nums[mid]) {
                // 如果 target 位於左半部分
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // 縮小範圍到左半部分
                } else {
                    left = mid + 1;  // 否則縮小範圍到右半部分
                }
            }
            // 否則右半部分是有序的
            // 如果中間的數小於最右邊的數，則右半段是有序的
            // 0　　1　　2　　 4　　5　　6　　7
            else {
                // 如果 target 位於右半部分
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // 縮小範圍到右半部分
                } else {
                    right = mid - 1;  // 否則縮小範圍到左半部分
                }
            }
        }

        // 如果找不到目標值，返回 -1
        return -1;
    }
};
