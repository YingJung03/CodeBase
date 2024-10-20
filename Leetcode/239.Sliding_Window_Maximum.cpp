class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;   // 存儲每個窗口內的數字索引。
        
        for (int i = 0; i < nums.size(); i++) {
            // 移除不在窗口範圍內的元素（即左邊界以外的元素）
            if (!deq.empty() && deq.front() < i - k + 1) { 
                deq.pop_front();
            }
            
            // 移除隊列內所有比當前元素小的元素，因為它們不可能再成為窗口內的最大值
            while (!deq.empty() && nums[deq.back()] < nums[i]) {
                deq.pop_back();
            }
            
            // 將當前元素的索引加入隊列
            deq.push_back(i);
            
            // 當窗口達到大小 `k` 時，記錄當前窗口的最大值
            if (i >= k - 1) {
                ans.push_back(nums[deq.front()]);
            }
        }
        
        return ans;
    }
};
