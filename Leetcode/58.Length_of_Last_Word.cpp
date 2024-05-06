class Solution {
public:
    //從字串的尾端開始，找到最後一個單字的開頭，然後計算該單字的長度。
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            }
            //當遇到空格字元且正在計算單字的長度時，程式會立即結束迴圈
            else if (counting) {    
                break;
            }
        }
        return length;
    }
};