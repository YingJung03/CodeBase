class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1){
            return false; // 不可能為完全平方數
        }
        // 存儲更大範圍的整數值，通常比 int 擁有更大的存儲空間和表示範圍。
        long long low=1;
        long long high=num;
        while(low<=high){
            long long mid=low+(high-low) / 2;
            long long sqrt=mid*mid;
            
            if(sqrt>num){
                high=mid-1;
            }else if(sqrt<num){
                low=mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};