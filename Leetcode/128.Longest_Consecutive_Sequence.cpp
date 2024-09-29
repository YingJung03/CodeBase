class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // numSet 會過濾 nums的重複元素
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : numSet) {
            // numSet.end()==NULL
            // 如果 n-1 不存在於 numSet，代表 n 是子序列的起點
            if (numSet.find(n - 1) == numSet.end()) {
                int length = 1;
                // 如果 n + length 存在於 numSet，則不斷檢查接下來的數字
                // 如果不存在則跳出迴圈
                while (numSet.find(n + length) != numSet.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
