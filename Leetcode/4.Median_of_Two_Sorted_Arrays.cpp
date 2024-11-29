class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 合併兩個陣列
        vector<int> merged = nums1; // 將 nums1 複製到 merged
        merged.insert(merged.end(), nums2.begin(), nums2.end()); // 將 nums2 加入到 merged

        // 對合併後的陣列排序
        sort(merged.begin(), merged.end());

        // 計算中位數
        int mergedLen = merged.size();
        if (mergedLen % 2 == 0) {
            // 偶數情況：取中間兩個數的平均值
            int mid1 = merged[mergedLen / 2 - 1];
            int mid2 = merged[mergedLen / 2];
            return (mid1 + mid2) / 2.0; // 返回平均值，確保是浮點數
        } else {
            // 奇數情況：取中間的數
            return merged[mergedLen / 2];
        }
    }
};
