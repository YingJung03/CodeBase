class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        
        // pair 將2個資料組合成一組資料，就是unordered_map<key, value>，這樣才可以將值存到hash
        // 要做頻率比較，所以創建兩個 pair
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            // a.second < b.second
            // 意思是由小到大排序，但在priority_queue必須要頭尾相反
            // 所以是由"大"到小，"大"就是maxHeap的意思
            
            // 所以反過來 a.second > b.second
            // 意思是由大到小排序，但在priority_queue必須要頭尾相反
            // 所以是由"小"到大，"小"就是minHeap的意思
            return a.second < b.second;
        };

        // 重構 priority_queue的通用寫法
        // 參數一：想要更改的型態
        // 參數二：vector<塞入想要更改的型態>（同參數1）
        // 參數三：decltype(塞入比較函式)
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> maxHeap(comp);
        
        for (auto& entry : counter) {
            maxHeap.push({entry.first, entry.second});
        }
        
        vector<int> res;
        while (k-- > 0) {
            res.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        
        return res;        
    }
};
