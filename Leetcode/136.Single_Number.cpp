class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto x: m){          
            if(x.second < 2){
                return x.first;
            }
        }
        return 0;
    }
};