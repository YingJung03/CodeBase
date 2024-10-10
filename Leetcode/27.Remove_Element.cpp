class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int position=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[position]=nums[i];
                position++;
            }
        }
        return position;
        
    }
};