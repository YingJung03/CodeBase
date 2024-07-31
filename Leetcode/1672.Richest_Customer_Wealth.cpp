class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich=0;
        int num;
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            int wealth=0;
            for(int j=0;j<accounts[i].size();j++){
                num=accounts[i][j];
                wealth+=num;
            }
            if(rich<wealth){
                rich=wealth;
            }

        }
        return rich;
        
    }
};