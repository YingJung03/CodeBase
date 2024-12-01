class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()){
            return false;
        }

        // 記錄magazine字母的頻率
        unordered_map<char, int> m;
        
        
        for (char i : magazine) {
            m[i]++;
        }

        
        for (char i : ransomNote) {
            // 如果某個字母的頻率不足，返回 false
            if (m[i] <= 0) {
                return false;
            }
            // 減少該字母的頻率
            m[i]--;
        }

        // 如果所有字母都滿足條件，返回 true
        return true;
        
    }
};