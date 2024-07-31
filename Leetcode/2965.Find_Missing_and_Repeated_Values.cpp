class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> m;
        vector<int> result;
        int times=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                times+=1;
               
                if (m.find(grid[i][j])!=m.end()) {
                    result.push_back(grid[i][j]);
                    
                }else{
                    m[grid[i][j]]++;
                }
               
            }
            
        }

        for(int z=1;z<=grid.size()*grid.size();z++){
            //m.end():空，所以該段意思是map裡沒有grid[i][j]就做括號裡的事
            if (m.find(z)==m.end()) {
                    result.push_back(z);
                    
                }
        }
        return result;
        
    }
};