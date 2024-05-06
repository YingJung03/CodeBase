class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string output = "";
        int end=0,start=0;
        while(end<nums.size()){
            if(output.length()==0) output+=to_string(nums[end]);
            else if(nums[end]!=nums[end-1]+1){
                if(start!=end-1) output+= "->" + to_string(nums[end-1]);
                ans.push_back(output);
                output="";
                start = end;
                continue;
            }
            end++;
        }
        if(start!=end-1 && start!=end) output+= "->" + to_string(nums[end-1]);
        if(output.length()!=0) ans.push_back(output);
        return ans;
    }
};