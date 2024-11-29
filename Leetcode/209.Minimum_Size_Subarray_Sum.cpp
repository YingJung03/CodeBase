class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0; 
        int currentSum = 0; // 當前子陣列的總和
        int minLength = INT_MAX; // 最小長度，初始為最大值

        for (int i = 0; i < n; i++) {
            currentSum += nums[i]; // 擴展右邊界

            // 當子陣列的和大於或等於 target 時，開始收縮左邊界
            while (currentSum >= target) {
                minLength = min(minLength, i - start + 1); // 更新最小長度
                currentSum -= nums[start]; // 收縮左邊界，移除左端的數字
                start++;
            }
        }

        
        return minLength == INT_MAX ? 0 : minLength;
    }
};
