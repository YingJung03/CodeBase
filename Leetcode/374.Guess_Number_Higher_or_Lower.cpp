/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */


class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2; // 防止溢位的中點計算

            // 使用 guess API 進行判斷
            int result = guess(mid);
            if (result == -1) { 
                end = mid - 1; // 如果猜的數太大，調整右邊界
            } else if (result == 1) { 
                start = mid + 1; // 如果猜的數太小，調整左邊界
            } else {
                return mid; // 如果猜對了，直接返回
            }
        }
        return -1;
    }
};
