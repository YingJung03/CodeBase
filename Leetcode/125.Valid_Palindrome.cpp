class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for (char ch : s) {
            // 只保留字母和數字
            if (isalnum(ch)) {
                result += tolower(ch);
            }
        }
        
        // 判斷字串長度為奇數還偶數
        int a=result.size()/2;
        if (a%2==0){
            a=a-1;
        }

        for(int i =0,j=result.size()-1;i<=a;i++,j--){
            if(result[i]!=result[j])
            {
                return false;
            }
        }
        return true;
        
    }
};
