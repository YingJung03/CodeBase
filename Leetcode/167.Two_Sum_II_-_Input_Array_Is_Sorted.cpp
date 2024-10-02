class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n1=0;
        int n2=numbers.size()-1;
        while(n1<n2){
            int now_sum=numbers[n1]+numbers[n2];
            if(now_sum>target){
                n2--;
            }else if(now_sum<target){
                n1++;
            }else{
                return {n1+1,n2+1};
            }
        }
        return {};
    }
};