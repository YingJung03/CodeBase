class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxNum = *max_element(piles.begin(), piles.end());
        
        int left = 1; 
        int right = maxNum; 

        while (left < right) {
            int mid = (left + right) / 2; 
            int timeSum = 0; 
        
            for (int i = 0; i < piles.size(); i++) {
                timeSum += (piles[i] + mid - 1) / mid;  // 向上取整
            }
            if (timeSum <= h) {
                right = mid;
            } else { 
                left = mid + 1;
            }
        }

        return left;
    }
};
