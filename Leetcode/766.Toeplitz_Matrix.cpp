class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            int num=matrix[0][i];
            for(int row=1,col=i+1;row<matrix.size() && col<matrix[0].size();row++,col++){
                int now_num=matrix[row][col];
                if(num!=now_num){
                    return false;
                }
            }
        }
        
        for(int j=1;j<matrix.size();j++){
            int num=matrix[j][0];
            for(int row=j+1,col=1;row<matrix.size() && col<matrix[0].size();row++,col++){
                int now_num=matrix[row][col];
                if(num!=now_num){
                    return false;
                }
            }

        }
        return true;
        
    }
};