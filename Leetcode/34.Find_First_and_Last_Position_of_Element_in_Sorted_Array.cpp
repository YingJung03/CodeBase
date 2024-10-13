class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);  // 預設返回 [-1, -1]
        if (nums.empty()){
            return result;
        }

        // 找到 target 第一次出現的位置
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            // 不寫mid=(right +left) / 2的原因為避免溢位，結果超出整數最大值範圍，所以先right - left 縮小範圍
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;  // 繼續在左半部分搜尋
            } else {
                left = mid + 1;
            }
        }

        // 檢查 left 是否超出範圍以及是否找到了 target
        if (left >= nums.size() || nums[left] != target) {
            return result;  // 沒有找到 target
        }
        result[0] = left;  // 紀錄第一次出現的位置

        // 找到 target 最後一次出現的位置
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;  // 繼續在右半部分搜尋
            } else {
                right = mid - 1;
            }
        }

        result[1] = right;  // 紀錄最後一次出現的位置
        return result;
    }
};
