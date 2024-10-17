class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        // 計算 t 字母出現的次數
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        
        int i = 0;
        int j = 0;
        
        int counter = t.size();
        
        int minStart = 0;
        int minLength = INT_MAX;
        // 判斷 s 裡面有沒有 t 裡面的字母
        
        while (j < s.size()) {
            if (m[s[j]] > 0) {
                counter--;
            }
            m[s[j]]--;
            j++;
            
            while (counter == 0) {
                if (j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }
                m[s[i]]++;

                if (m[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }
        
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }
};
