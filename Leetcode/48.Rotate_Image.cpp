class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> new_matrix = matrix;
        for(int i=0;i<new_matrix.size();i++){
            int column=0;
            for(int j=new_matrix.size()-1;j>=0;j--){
                matrix[i][column++]=new_matrix[j][i];
            }
        }
    }
};