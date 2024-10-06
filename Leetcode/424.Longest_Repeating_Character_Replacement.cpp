class Solution {
public:
    int characterReplacement(string s, int k) {
        // 字元頻率計數器，大小為 26，因為只處理大寫字母 A-Z
        int count[26] = {0};
        
        int l = 0;  // 左指標
        int max_count = 0;  // 當前窗口內出現最多次數的字母的次數
        int res = 0;  // 最終結果：最長子串的長度

        // 遍歷字串，r 為右指標
        for (int r = 0; r < s.size(); r++) {
            // 更新當前字元的頻率
            count[s[r] - 'A']++;
            cout << s[r] << endl;
            cout << count[1] << endl;
            // 更新 max_count，表示當前窗口內出現最多次數的字母的次數
            max_count = max(max_count, count[s[r] - 'A']);
            
            // 如果需要替換的字元數量超過 k，則收縮窗口
            // (當前窗口長度 r - l + 1 減去最多字母的次數，表示需要替換的字母數量)
            if (r - l + 1 - max_count > k) {
                // 減少左指標對應字元的頻率，並移動左指標
                count[s[l] - 'A']--;
                l++;
            }
            
            // 更新結果，當前窗口的大小為 r - l + 1
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};
