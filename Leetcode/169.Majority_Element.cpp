// Approach 2: Hash Map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        n = n/2;
        for(auto x: m){             //x是row <key,value>
            if(x.second > n){
                return x.first;
            }
        }
        return 0;
    }
};
