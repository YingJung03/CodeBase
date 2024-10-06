class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            // 找看看s[r]元素是否存在 charSet，若存在代表有重複，必須將它移除
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            // 若不存在，則新增至charSet
            charSet.insert(s[r]);
            // 計算次數
            res = max(res, r - l + 1);
        }
        return res;
    }
};
