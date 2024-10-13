class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // ans用來存儲當前最接近 target 的差值的絕對值
        // 整數型別 int 的最大值，確保在第一次比較時，任何三數之和與 target 的差距都會小於 INT_MAX
        int ans = INT_MAX;
        // result 用來存儲最接近的三數之和
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (abs(sum - target) < abs(ans)) {
                    ans = sum - target;
                    result = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};