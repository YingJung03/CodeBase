class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // 前綴乘積:從左到右遍歷數組時，每個元素的左邊所有數的乘積，不包含當前元素自己。
        int left_product = 1;
        for(int i=0;i<n;i++){
            output[i]=left_product;
            left_product*=nums[i];
        }

        // 後綴乘積:從右到左遍歷數組時，每個元素的右邊所有數的乘積，不包含當前元素自己。
        int right_product = 1;
        for(int i=n-1;i>=0;i--){
            output[i]*=right_product;
            right_product*=nums[i];
        }
        return output;

    }
};
