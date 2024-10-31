// 方法 1 hash map
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int,int>m;

//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]++;
//         }

//         for(auto x:m){
//             if(x.second>1){
//                 return x.first;
//             }
//         }
//         return 0;
        
//     }
// };

// 方法 2 listed list
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
};